#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE

#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
# define BUFF_SIZE 10

int		get_next_line(const int fd, char **line);

#endif
