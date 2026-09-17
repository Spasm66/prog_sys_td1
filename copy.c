#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <assert.h>

#include "error.h"

int main(int argc, char **argv)
{
    int     fi;
    int     fo;
    long    n;
    int     r;
    
    if  (argc == 4) {
        fi = open(argv[1], O_RDONLY);
        check_syscall(fi, "chemin : %s", argv[1]);
        fo = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0640);
        n = atol(argv[3]);
        char buffer[n];
        r = 0;
        while((r = read(fi, buffer, n)) > 0){
            write(fo, buffer, r);
        }
    }
    return EXIT_SUCCESS;
}
