/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 18:35:32 by alcierra          #+#    #+#             */
/*   Updated: 2022/04/12 16:06:34 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	ft_free_map(t_map *map)
{
	int		i;

	if (!map)
		return ;
	if (map->map)
	{
		i = 0;
		while (map->map[i])
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
	}
	free(map);
}

int window_close(void *params)
{
	(void) params;
	exit(0);
}

int	main(int argc, char **argv)
{
	char	*point;
	t_map	*map;

	if (argc != 2)
	{
		write(2, "Arguments Error\n", 16);
		return (0);
	}
	point = ft_strrchr(argv[1], '.');
	if (point == NULL)
		ft_error("Error: Map: there is no extension\n");
	if (ft_strncmp(point + 1, "ber", 4) != 0)
		ft_error("Error: Map: file extension not .ber\n");
	map = ft_parse(argv[1]);
	map->mlx = mlx_init();

	map->mlx_win = mlx_new_window(map->mlx, map->width * 100, map->heigth * 100,
							 "So Long");
	mlx_hook(map->mlx_win, 17, 0, window_close, NULL);
	ft_draw_all(map);
	mlx_loop(map->mlx);
	ft_free_map(map);
}
