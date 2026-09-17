#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <assert.h>

#include "error.h"

int main(int argc, char **argv)
{
    char    *c;
    int     fi;
    int     fo;
    long    n;
    
    if  (argc == 4) {
        fi = open(argv[1], O_RDONLY);
        fo = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0640);
        n = atol(argv[3]);
        c = malloc(sizeof(char)*n);
        read(fi, &c, n);
        write(fo, &c, n);
    }
    return EXIT_SUCCESS;
}
