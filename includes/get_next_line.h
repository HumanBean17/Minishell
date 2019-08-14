
#ifndef GNL_GET_NEXT_LINE_H
# define GNL_GET_NEXT_LINE_H

#include <fcntl.h>
#include "libft.h"
#define BUFF_SIZE 1024

int			get_next_line(const int fd, char **line);

#endif
