/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:02:02 by alcierra          #+#    #+#             */
/*   Updated: 2022/05/22 11:21:04 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	draw_objects(t_game *game)
{
	t_list		*list;
	t_player	*p;

	list = game->players;
	while (list)
	{
		p = ((t_player *) list->content);
		draw_map_player(game, p);
		list = list->next;
	}
	list = game->collectibles;
	while (list)
	{
		draw_map_collectible(game, (t_object *) list->content);
		list = list->next;
	}
}

static void	draw_cell(t_game *game, unsigned int i, unsigned int j)
{
	void	*img;

	img = game->textures.background.image;
	mlx_put_image_to_window(game->mlx, game->mlx_win, img,
		game->part_width * j + game->padding_rl,
		game->part_height * i + game->padding_tb);
	img = NULL;
	if (game->map[i][j] == '1')
		draw_map_wall(game, j, i);
	else if (game->map[i][j] == 'E')
		img = ((t_texture *) game->textures
				.exits_close->content)->image;
	else
		img = NULL;
	if (img)
		mlx_put_image_to_window(game->mlx, game->mlx_win, img,
			game->part_width * j + game->padding_rl,
			game->part_height * i + game->padding_tb);
}

void	ft_draw_all(t_game *game)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			draw_cell(game, i, j);
			j++;
		}
		i++;
	}
	draw_objects(game);
}
