/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:02:20 by alcierra          #+#    #+#             */
/*   Updated: 2022/04/13 19:02:26 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_objects_requirements(t_game *game, int *params)
{
	if (params[2] < 1)
		ft_error("Error: Map: collectible items not exist\n");
	if (params[3] < 1)
		ft_error("Error: Map: exit not exist\n");
	if (!game->players)
		ft_error("Error: Map: player not exist\n");
	if (!game->exits)
		ft_error("Error: Map: starting position not exist\n");
}

void	ft_check_symbol(t_game *map, unsigned int i,
	unsigned int j, int *params)
{
	if (ft_strchr("01CEP", map->map[i][j]) == NULL)
		ft_error("Error: Map: unacceptable characters\n");
	if (map->map[i][j] == '0')
		params[0]++;
	else if (map->map[i][j] == '1')
		params[1]++;
	else if (map->map[i][j] == 'C')
		params[2]++;
	else if (map->map[i][j] == 'E')
		params[3]++;
	else if (map->map[i][j] == 'P')
	{
		params[4]++;
		map->map[i][j] = '0';
	}
}

void	ft_check_map_around_wall(t_game *map)
{
	unsigned int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->map[0][i] != '1')
			ft_error("Error: Map: map not surrounded by wall (top)\n");
		else if (map->map[map->height - 1][i] != '1')
			ft_error("Error: Map: map not surrounded by wall (bottom)\n");
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->map[i][0] != '1')
			ft_error("Error: Map: map not surrounded by wall (left)\n");
		else if (map->map[i][map->width - 1] != '1')
			ft_error("Error: Map: map not surrounded by wall (right)\n");
		i++;
	}
}

void	ft_map_check(t_game *game)
{
	unsigned int	str_i;
	unsigned int	map_i;
	int				params[5];

	ft_memset(params, 0, sizeof(int) * 5);
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
			ft_check_symbol(game, map_i, str_i, params);
			str_i++;
		}
		map_i++;
	}
	ft_check_map_around_wall(game);
	ft_check_objects_requirements(game, params);
}
