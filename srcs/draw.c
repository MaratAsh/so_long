/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:00:00 by alcierra          #+#    #+#             */
/*   Updated: 2022/05/23 21:22:45 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw(t_game *game, void *img, unsigned x, unsigned y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, img, x, y);
}

void	draw_map_background(unsigned x, unsigned y, t_game *game)
{
	draw(game, game->textures.background.image,
		x * game->part_width + game->padding_rl,
		y * game->part_height + game->padding_tb);
}

void	draw_map_collectible(t_game *game, t_object *c)
{
	t_texture		*t;

	t = (t_texture *) c->texture->content;
	draw(game, t->image,
		c->map_x * game->part_width + game->padding_rl,
		c->map_y * game->part_height + game->padding_tb);
}

void	draw_map_player(t_game *game, t_player *p)
{
	t_texture		*t;

	t = (t_texture *) p->texture->content;
	draw(game, t->image,
		p->map_x * game->part_width + game->padding_rl,
		p->map_y * game->part_height + game->padding_tb);
}

void	draw_map_player_state(t_game *game, t_player *p)
{
	t_texture		*t;
	t_state			*s;

	s = (t_state *) p->states->content;
	t = (t_texture *) s->texture;
	draw(game, t->image, s->x, s->y);
}
