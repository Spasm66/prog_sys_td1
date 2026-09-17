#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv) {
    int     in;
    off_t   val;
    off_t pos;

    in = open(argv[1], O_RDONLY);
    pos = strtoul(argv[2]);
    lseek(in, pos, SEEK_SET);
    read(in, &val, sizeof(val));
    printf("%ld\n", val);
}