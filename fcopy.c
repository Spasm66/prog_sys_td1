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
    FILE    *fi;
    FILE    *fo;
    
    if  (argc == 3) {
        fi = fopen(argv[1], "r");
	check(fi != NULL, "argv[1]");
        fo = fopen(argv[2], "w+");
        while (fread(&c, sizeof(char), 1, fi) > 0) {
            fwrite(&c, sizeof(char), 1, fo);
        }
    }
    return EXIT_SUCCESS;
}
