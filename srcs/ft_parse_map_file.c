/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 18:35:32 by alcierra          #+#    #+#             */
/*   Updated: 2022/05/23 21:19:34 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_get_content(int fd)
{
	char			*str;
	char			*new_str;
	int				buff_c;
	long long int	readed;
	long long int	str_len;

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

int	ft_parse_map_file(char *map_file, t_game *game)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		ft_error("Error: File: file not exist\n");
	game->str = ft_get_content(fd);
	if (!(game->str))
		return (1);
	if (ft_strlen(game->str) <= MAP_EXACTLY_NOT_VALID
		|| ft_strnstr(game->str, "\n\n", ft_strlen(game->str)))
		ft_error("Error: Map: not valid card\n");
	game->map = ft_split_inline(game->str, (int) '\n');
	close(fd);
	return (0);
}
