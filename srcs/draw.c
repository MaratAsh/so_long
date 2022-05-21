/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:00:00 by alcierra          #+#    #+#             */
/*   Updated: 2022/05/18 24:00:00 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw(t_game *game, void *img, unsigned x, unsigned y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, img, x, y);
}

void	draw_map_background(unsigned x, unsigned y, t_game *game)
{
	draw(game, game->textures.background.image, x * game->part_width,
		 y * game->part_height);
}

void	draw_map_collectible(t_game *game, t_object *c)
{
	t_texture		*t;

	t = (t_texture *) c->texture->content;
	draw(game, t->image, c->map_x * game->part_width,
		 c->map_y * game->part_height);
}

void	draw_map_player(t_game *game, t_player *p)
{
	t_texture		*t;

	t = (t_texture *) p->texture->content;
	draw(game, t->image, p->map_x * game->part_width,
		 p->map_y * game->part_height);
}

void	draw_map_player_state(t_game *game, t_player *p)
{
	t_texture		*t;
	t_state			*s;

	s = (t_state *) p->states->content;
	t = (t_texture *) s->texture;
	draw(game, t->image, s->x, s->y);
}

void	draw_map_exit(t_game *game, t_object *o)
{
	t_texture		*t;

	t = (t_texture *) o->texture->content;
	draw(game, t->image, o->map_x * game->part_width,
		 o->map_y * game->part_height);
}
