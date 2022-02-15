/* tee.c

   Usage: tee file 

   This program copies the input from the standard input to files or to standard output


        tee 
*/
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include "tlpi_hdr.h"

int
main(int argc, char *argv[])
{
    size_t len;
    off_t offset;
    int fd, ap, j;
    unsigned char *buf;

    if (strcmp(argv[1], "--help") == 0)
        usageErr("%s file ...\n",argv[0]);

    fd = open(argv[1], O_RDWR | O_CREAT,
                S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
                S_IROTH | S_IWOTH);                     /* rw-rw-rw- */
    if (fd == -1)
        errExit("open");


    if (close(fd) == -1)
        errExit("close");

    exit(EXIT_SUCCESS);
}
