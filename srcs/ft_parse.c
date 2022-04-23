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

char	*ft_get_content(int fd)
{
	char	*str;
	char	*new_str;
	int		buff_c;
	size_t	readed;
	size_t	str_len;

	buff_c = 1;
	str = malloc(BUFFER_SIZE * buff_c + 1);
	readed = read(fd, str, BUFFER_SIZE);
	str_len = 0;
	while (readed > 0)
	{
		str[str_len + readed] = 0;
		str_len = ft_strlen(str);
		new_str = malloc(str_len + BUFFER_SIZE * (buff_c + 1) + 1);
		ft_strlcpy(new_str, str, str_len + 1);
		free(str);
		str = new_str;
		readed = read(fd, str + str_len, BUFFER_SIZE);
		buff_c++;
	}
	str[BUFFER_SIZE * buff_c] = 0;
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
	printf("\"%s\"\n", str);
	if (!str)
		return (map);
	if (ft_strlen(str) <= MAP_EXACTLY_NOT_VALID
		|| ft_strnstr(str, "\n\n", ft_strlen(str)))
		ft_error("Error: Map: not valid card\n");
	map->map = ft_split_inline(str, '\n');
	int i = 0;
	while (map->map[i])
	{
		char *string = map->map[i];
		(void) string;
		i++;
	}
	ft_map_check(map);
	map->width = ft_strlen(map->map[0]);
	if (str)
		free(str);
	close(fd);
	return (map);
}
