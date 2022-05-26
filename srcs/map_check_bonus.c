/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:02:20 by alcierra          #+#    #+#             */
/*   Updated: 2022/04/13 19:02:26 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_symbol_bonus(t_game *map, unsigned int i,
	unsigned int j, int *params)
{
	char *symb;
	char *str;

	str = "01CEPD";
	symb = ft_strchr(str, map->map[i][j]);
	if (symb == NULL)
		ft_error("Error: Map: unacceptable characters\n");
	params[symb - str]++;
	if (map->map[i][j] == 'P')
		map->map[i][j] = '0';
}

void	map_check_bonus(t_game *game)
{
	unsigned int	str_i;
	unsigned int	map_i;
	int				params[6];

	ft_memset(params, 0, sizeof(int) * 6);
	if (!(game->map))
		ft_error("Error: Malloc: split have not allocate the memory\n");
	map_i = 0;
	while (game->map[map_i])
	{
		if (ft_strlen(game->map[map_i]) != game->width)
			ft_error("Error: Map: game size error\n");
		str_i = 0;
		while (game->map[map_i][str_i])
		{
			check_symbol_bonus(game, map_i, str_i, params);
			str_i++;
		}
		map_i++;
	}
	ft_check_map_around_wall(game);
	ft_check_objects_requirements(game, params);
}
