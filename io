io(3)                                                                                            Linux AIO                                                                                           io(3)

NAME
       io - Asynchronous IO

SYNOPSIS
       #include <errno.h>

       #include <libaio.h>

DESCRIPTION
       The libaio library defines a new set of I/O operations which can significantly reduce the time an application spends waiting at I/O.  The new functions allow a program to initiate one or more I/O
       operations and then immediately resume normal work while the I/O operations are executed in parallel.

       These functions are part of the library with realtime functions named libaio.  They are not actually part of the libc binary.  The implementation of these functions can be done using  support  in
       the kernel.

       All  IO  operations  operate  on files which were opened previously.  There might be arbitrarily many operations running for one file.  The asynchronous I/O operations are controlled using a data
       structure named struct iocb It is defined in libaio.h as follows.

       typedef struct io_context *io_context_t;

       typedef enum io_iocb_cmd {
               IO_CMD_PREAD = 0,
               IO_CMD_PWRITE = 1,

               IO_CMD_FSYNC = 2,
               IO_CMD_FDSYNC = 3,

               IO_CMD_POLL = 5,
               IO_CMD_NOOP = 6,
       } io_iocb_cmd_t;

       struct io_iocb_common {
               void            *buf;
               unsigned        __pad1;
               long            nbytes;
               unsigned        __pad2;
               long long       offset;
               long long       __pad3, __pad4;
       };      /* result code is the amount read or -'ve errno */

       struct iocb {
               void            *data;
               unsigned        key;
               short           aio_lio_opcode;
               short           aio_reqprio;
               int             aio_fildes;
               union {
                       struct io_iocb_common           c;
                       struct io_iocb_vector           v;
                       struct io_iocb_poll             poll;
                       struct io_iocb_sockaddr saddr;
               } u;
       };

       int aio_fildes
              This element specifies the file descriptor to be used for the operation.  It must be a legal descriptor, otherwise the operation will fail.

              The device on which the file is opened must allow the seek operation.  I.e., it is not possible to use any of the IO operations on devices like terminals where an lseek(2) call would  lead
              to an error.

       long u.c.offset
              This  element  specifies  the offset in the file at which the operation (input or output) is performed.  Since the operations are carried out in arbitrary order and more than one operation
              for one file descriptor can be started, one cannot expect a current read/write position of the file descriptor.

       void *buf
              This is a pointer to the buffer with the data to be written or the place where the read data is stored.

       long u.c.nbytes
              This element specifies the length of the buffer pointed to by io_buf.

       int aio_reqprio
              Is not currently used.

       IO_CMD_PREAD
              Start a read operation.  Read from the file at position u.c.offset and store the next u.c.nbytes bytes in the buffer pointed to by buf.

       IO_CMD_PWRITE
              Start a write operation.  Write u.c.nbytes bytes starting at buf into the file starting at position u.c.offset.

       IO_CMD_NOP
              Do nothing for this control block.  This value is useful sometimes when an array of struct iocb values contains holes, i.e., some of the values must not be handled although the whole array
              is presented to the io_submit(3) function.

       IO_CMD_FSYNC
       IO_CMD_POLL
              This is experimental.

EXAMPLE
       /*
        * Simplistic version of copy command using async i/o
        *
        * From:  Stephen Hemminger <shemminger@osdl.org>
        * Copy file by using a async I/O state machine.
        * 1. Start read request
        * 2. When read completes turn it into a write request
        * 3. When write completes decrement counter and free resources
        *
        *
        * Usage: aiocp file(s) desination
        */

       #include <unistd.h>
       #include <stdio.h>
       #include <sys/types.h>
       #include <sys/stat.h>
       #include <sys/param.h>
       #include <fcntl.h>
       #include <errno.h>

       #include <libaio.h>

       #define AIO_BLKSIZE (64*1024)
       #define AIO_MAXIO   32

       static int busy = 0;          // # of I/O's in flight
       static int tocopy = 0;        // # of blocks left to copy
       static int dstfd = -1;        // destination file descriptor
       static const char *dstname = NULL;
       static const char *srcname = NULL;

       /* Fatal error handler */
       static void io_error(const char *func, int rc)
       {
           if (rc == -ENOSYS)
            fprintf(stderr, "AIO not in this kernel\n");
           else if (rc < 0 && -rc < sys_nerr)
            fprintf(stderr, "%s: %s\n", func, sys_errlist[-rc]);
           else
            fprintf(stderr, "%s: error %d\n", func, rc);

           if (dstfd > 0)
            close(dstfd);
           if (dstname)
            unlink(dstname);
           exit(1);
       }

       /*
        * Write complete callback.
        * Adjust counts and free resources
        */
       static void wr_done(io_context_t ctx, struct iocb *iocb, long res, long res2)
       {
           if (res2 != 0) {
            io_error("aio write", res2);
           }
           if (res != iocb->u.c.nbytes) {
            fprintf(stderr, "write missed bytes expect %d got %d\n", iocb->u.c.nbytes, res2);
            exit(1);
           }
           --tocopy;
           --busy;
           free(iocb->u.c.buf);

           memset(iocb, 0xff, sizeof(iocb));   // paranoia
           free(iocb);
           write(2, "w", 1);
       }

       /*
        * Read complete callback.
        * Change read iocb into a write iocb and start it.
        */
       static void rd_done(io_context_t ctx, struct iocb *iocb, long res, long res2)
       {
           /* library needs accessors to look at iocb? */
           int iosize = iocb->u.c.nbytes;
           char *buf = iocb->u.c.buf;
           off_t offset = iocb->u.c.offset;

           if (res2 != 0)
            io_error("aio read", res2);
           if (res != iosize) {
            fprintf(stderr, "read missing bytes expect %d got %d\n", iocb->u.c.nbytes, res);
            exit(1);
           }

           /* turn read into write */
           io_prep_pwrite(iocb, dstfd, buf, iosize, offset);
           io_set_callback(iocb, wr_done);
           if (1 != (res = io_submit(ctx, 1, &iocb)))
            io_error("io_submit write", res);
           write(2, "r", 1);
       }

       int main(int argc, char *const *argv)
       {
           int srcfd;
           struct stat st;
           off_t length = 0, offset = 0;
           io_context_t myctx;

           if (argc != 3 || argv[1][0] == '-') {
            fprintf(stderr, "Usage: aiocp SOURCE DEST");
            exit(1);
           }
           if ((srcfd = open(srcname = argv[1], O_RDONLY)) < 0) {
            perror(srcname);
            exit(1);
           }
           if (fstat(srcfd, &st) < 0) {
            perror("fstat");
            exit(1);
           }
           length = st.st_size;

           if ((dstfd = open(dstname = argv[2], O_WRONLY | O_CREAT, 0666)) < 0) {
            close(srcfd);
            perror(dstname);
            exit(1);
           }

           /* initialize state machine */
           memset(&myctx, 0, sizeof(myctx));
           io_queue_init(AIO_MAXIO, &myctx);
           tocopy = howmany(length, AIO_BLKSIZE);

           while (tocopy > 0) {
            int i, rc;
            /* Submit as many reads as once as possible upto AIO_MAXIO */
            int n = MIN(MIN(AIO_MAXIO - busy, AIO_MAXIO / 2),
                     howmany(length - offset, AIO_BLKSIZE));
            if (n > 0) {
                struct iocb *ioq[n];

                for (i = 0; i < n; i++) {
                 struct iocb *io = (struct iocb *) malloc(sizeof(struct iocb));
                 int iosize = MIN(length - offset, AIO_BLKSIZE);
                 char *buf = (char *) malloc(iosize);

                 if (NULL == buf || NULL == io) {
                     fprintf(stderr, "out of memory\n");
                     exit(1);
                 }

                 io_prep_pread(io, srcfd, buf, iosize, offset);
                 io_set_callback(io, rd_done);
                 ioq[i] = io;
                 offset += iosize;
                }

                rc = io_submit(myctx, n, ioq);
                if (rc < 0)
                 io_error("io_submit", rc);

                busy += n;
            }

            // Handle IO's that have completed
            rc = io_queue_run(myctx);
            if (rc < 0)
                io_error("io_queue_run", rc);

            // if we have maximum number of i/o's in flight
            // then wait for one to complete
            if (busy == AIO_MAXIO) {
                rc = io_queue_wait(myctx, NULL);
                if (rc < 0)
                 io_error("io_queue_wait", rc);
            }

           }

           close(srcfd);
           close(dstfd);
           exit(0);
       }

       /*
        * Results look like:
        * [alanm@toolbox ~/MOT3]$ ../taio kernel-source-2.4.8-0.4g.ppc.rpm abc
        * rrrrrrrrrrrrrrrwwwrwrrwwrrwrwwrrwrwrwwrrwrwrrrrwwrwwwrrwrrrwwwwwwwwwwwwwwwww
        * rrrrrrrrrrrrrrwwwrrwrwrwrwrrwwwwwwwwwwwwwwrrrrrrrrrrrrrrrrrrwwwwrwrwwrwrwrwr
        * wrrrrrrrwwwwwwwwwwwwwrrrwrrrwrrwrwwwwwwwwwwrrrrwwrwrrrrrrrrrrrwwwwwwwwwwwrww
        * wwwrrrrrrrrwwrrrwwrwrwrwwwrrrrrrrwwwrrwwwrrwrwwwwwwwwrrrrrrrwwwrrrrrrrwwwwww
        * wwwwwwwrwrrrrrrrrwrrwrrwrrwrwrrrwrrrwrrrwrwwwwwwwwwwwwwwwwwwrrrwwwrrrrrrrrrr
        * rrwrrrrrrwrrwwwwwwwwwwwwwwwwrwwwrrwrwwrrrrrrrrrrrrrrrrrrrwwwwwwwwwwwwwwwwwww
        * rrrrrwrrwrwrwrrwrrrwwwwwwwwrrrrwrrrwrwwrwrrrwrrwrrrrwwwwwwwrwrwwwwrwwrrrwrrr
        * rrrwwwwwwwrrrrwwrrrrrrrrrrrrwrwrrrrwwwwwwwwwwwwwwrwrrrrwwwwrwrrrrwrwwwrrrwww
        * rwwrrrrrrrwrrrrrrrrrrrrwwwwrrrwwwrwrrwwwwwwwwwwwwwwwwwwwwwrrrrrrrwwwwwwwrw
        */

SEE ALSO
       io_cancel(3),  io_fsync(3),  io_getevents(3),  io_prep_fsync(3), io_prep_pread(3), io_prep_pwrite(3), io_queue_init(3), io_queue_release(3), io_queue_run(3), io_queue_wait(3), io_set_callback(3),
       io_submit(3), errno(3).

Linux                                                                                           2019-07-23                                                                                           io(3)
IO(3perl)                                                                            Perl Programmers Reference Guide                                                                            IO(3perl)

NAME
       IO - load various IO modules

SYNOPSIS
          use IO qw(Handle File); # loads IO modules, here IO::Handle, IO::File
          use IO;                 # DEPRECATED

DESCRIPTION
       "IO" provides a simple mechanism to load several of the IO modules in one go.  The IO modules belonging to the core are:

             IO::Handle
             IO::Seekable
             IO::File
             IO::Pipe
             IO::Socket
             IO::Dir
             IO::Select
             IO::Poll

       Some other IO modules don't belong to the perl core but can be loaded as well if they have been installed from CPAN.  You can discover which ones exist with this query:
       <https://metacpan.org/search?q=IO%3A%3A>.

       For more information on any of these modules, please see its respective documentation.

DEPRECATED
           use IO;                # loads all the modules listed below

       The loaded modules are IO::Handle, IO::Seekable, IO::File, IO::Pipe, IO::Socket, IO::Dir.  You should instead explicitly import the IO modules you want.

perl v5.36.0                                                                                    2022-12-12                                                                                       IO(3perl)
