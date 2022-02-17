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
    int fdwr,fdr = STDIN_FILENO, op, j;
    unsigned char *buf;

    if (argc < 2 || strcmp(argv[1], "--help") == 0)
        usageErr("%s file ...\n",argv[0]);

    if (argc >  1){
    	fdwr = open(argv[1], O_RDWR | O_CREAT,
                S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
                S_IROTH | S_IWOTH);
    }
    else {
    	fdwr = STDOUT_FILENO;
    }
    if (fdwr == -1)
        errExit("open");


    if (close(fdwr) == -1)
        errExit("close");

    exit(EXIT_SUCCESS);
}
