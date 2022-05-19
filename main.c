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

void	ft_free_map(t_game *map)
{
	if (!map)
		return ;
	if (map->str)
		free(map->str);
	if (map->map)
		free(map->map);
}

int window_close(t_game *params)
{
	(void) params;
	exit(0);
}

int	main(int argc, char **argv)
{
	char	*point;
	t_game	game;

	ft_memset(&game, 0, sizeof(game));
	if (argc != 2)
	{
		ft_error("Error: Arguments Count\n");
		return (0);
	}
	point = ft_strrchr(argv[1], '.');
	if (point == NULL)
		ft_error("Error: Map: there is no extension\n");
	if (ft_strncmp(point + 1, "ber", 4) != 0)
		ft_error("Error: Map: file extension not .ber\n");
	if (ft_parse_map_file(argv[1], &game))
		ft_error("Error: File: read error\n");
	ft_game_set(&game);

	game.mlx = mlx_init();
	load_textures(&game);
	set_textures(&game);
	game.mlx_win = mlx_new_window(game.mlx, game.width * 100,
								  game.height * 100, "So Long");
	mlx_key_hook(game.mlx_win, command_processing, &game);
	mlx_hook(game.mlx_win, 17, 0, window_close, &game);
	ft_draw_all(&game);
	mlx_loop_hook(game.mlx, moment_processing, &game);
	mlx_loop(game.mlx);
	ft_free_map(&game);
	return (0);
}
