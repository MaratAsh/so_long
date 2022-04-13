/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 18:35:32 by alcierra          #+#    #+#             */
/*   Updated: 2022/04/12 21:25:51 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>

# include <stdio.h>

# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define MAP_EXACTLY_NOT_VALID 11

typedef struct s_map
{
	char			**map;
	unsigned int	width;
	unsigned int	heigth;
	unsigned int	character_x;
	unsigned int	character_y;
}				t_map;

t_map	*ft_parse(char *map_file);
void	ft_error(char *msg);
void	ft_map_check(t_map *map);

#endif
