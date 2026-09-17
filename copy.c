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
        check_syscall(fi, "chemin : %s", argv[1]);
        fo = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0640);
        n = atol(argv[3]);
        c = malloc(sizeof(char)*n);
        while(read(fi, &c, n) > 0){
            write(fo, &c, n);
            c = calloc(1, n);
        }
        free(c);
    }
    return EXIT_SUCCESS;
}
