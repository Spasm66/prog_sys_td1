#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <assert.h>

#include "error.h"

int main(int argc, char **argv)
{
    char    c;
    int     fi;
    int     fo;
    
    if  (argc == 3) {
        fi = open(argv[1], O_RDONLY);
        fo = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0640);
        while (read(fi, &c, 1) > 0) {
            write(fo, &c, 1);
        }
    }
    return EXIT_SUCCESS;
}
