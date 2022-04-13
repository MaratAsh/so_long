/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 18:35:32 by alcierra          #+#    #+#             */
/*   Updated: 2022/04/13 19:02:45 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*ft_get_content(int fd)
{
	char	*str;
	char	*new_line;
	int		buffer_c;
	int		buff_read;

	buffer_c = 2;
	str = malloc(BUFFER_SIZE + 1);
	buff_read = read(fd, str, BUFFER_SIZE);
	while (buff_read == BUFFER_SIZE)
	{
		new_line = malloc(BUFFER_SIZE * buffer_c + 1);
		ft_strlcpy(new_line, str, ft_strlen(str) + 1);
		free(str);
		str = new_line;
		buff_read = read(fd, str + BUFFER_SIZE * (buffer_c - 1), BUFFER_SIZE);
		str[BUFFER_SIZE * (buffer_c - 1) + buff_read] = 0;
		buffer_c++;
	}
	return (str);
}

t_map	*ft_parse(char *map_file)
{
	int		fd;
	char	*str;
	t_map	*map;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		ft_error("Error: File: file not exist\n");
	map = ft_calloc(1, sizeof(map));
	if (!map)
		ft_error("Error: Malloc: allocation failed\n");
	str = ft_get_content(fd);
	if (!str)
		return (map);
	if (ft_strlen(str) <= MAP_EXACTLY_NOT_VALID
		|| ft_strnstr(str, "\n\n", ft_strlen(str)))
		ft_error("Error: Map: not valid card\n");
	map->map = ft_split(str, '\n');
	ft_map_check(map);
	map->width = ft_strlen(map->map[0]);
	if (str)
		free(str);
	close(fd);
	return (map);
}
