
#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <unistd.h>
# include <fcntl.h>

void	ft_parse(char *map_file);

typedef struct s_map
{
	char			**map;
	unsigned int	width;
	unsigned int	heigth;
}				t_map;

#endif
