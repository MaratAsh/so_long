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

void	ft_map_check(t_map *map)
{
	int	str_i;
	int	map_i;

	if (!(map->map))
		ft_error("Error: Malloc: map size error\n");
	map->width = ft_strlen(map->map[0]);
	map_i = 1;
	while (map->map[map_i])
	{
		if (ft_strlen(map->map[map_i]) != map->width)
			ft_error("Error: Map: map size error\n");
		str_i = 0;
		while (map->map[map_i][str_i])
		{
			if (ft_strchr("01CEP", map->map[map_i][str_i]) == NULL)
				ft_error("Error: Map: unacceptable characters\n");
			str_i++;
		}
		map_i++;
	}
	map->heigth = map_i;
}
