#include "get_next_line.h"
#include "stdio.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

int main(int argc, char **argv)
{
	int fd;
	int fd1;
	char *str;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	fd1 = open(argv[2], O_RDONLY);
    str = NULL;
    printf(KRED"%d \'%s\'\n"KNRM, get_next_line(fd, &str), str);
    free(str);
    printf(KGRN"%d \'%s\'\n"KNRM, get_next_line(fd1, &str), str);
    free(str);
	return (0);
}

