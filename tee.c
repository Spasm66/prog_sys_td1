#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "error.h"

int main(int argc, char **argv) {
	char	c;
	int	f;
	if (argc == 2) {
		f = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0640);
	}
	while (read(0, &c, 1) > 0) {
		write(1, &c, 1);
		write(f, &c, 1);
	}
	return 0;
}
