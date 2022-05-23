/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:00:00 by alcierra          #+#    #+#             */
/*   Updated: 2022/05/23 21:22:57 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static t_texture	*choose_wall_texture_2(t_game *game, int sides)
{
	t_texture	*t;

	if (sides == WALL_RL)
		t = &(game->textures.wall_rl);
	else if (sides == WALL_TB)
		t = &(game->textures.wall_tb);
	else if (sides == WALL_TRL)
		t = &(game->textures.wall_trl);
	else if (sides == WALL_TBL)
		t = &(game->textures.wall_tbl);
	else if (sides == WALL_BOTTOM)
		t = &(game->textures.wall_b);
	else
		t = &(game->textures.wall_all);
	return (t);
}

t_texture	*choose_wall_texture(t_game *game, int sides)
{
	t_texture	*t;

	if (sides == WALL_NO)
		t = &(game->textures.wall_no);
	else if (sides == WALL_TR)
		t = &(game->textures.wall_tr);
	else if (sides == WALL_BL)
		t = &(game->textures.wall_bl);
	else if (sides == WALL_RBL)
		t = &(game->textures.wall_rbl);
	else if (sides == WALL_RB)
		t = &(game->textures.wall_rb);
	else if (sides == WALL_TRB)
		t = &(game->textures.wall_trb);
	else if (sides == WALL_TL)
		t = &(game->textures.wall_tl);
	else if (sides == WALL_RIGHT)
		t = &(game->textures.wall_r);
	else if (sides == WALL_LEFT)
		t = &(game->textures.wall_l);
	else if (sides == WALL_TOP)
		t = &(game->textures.wall_t);
	else
		t = choose_wall_texture_2(game, sides);
	return (t);
}

void	draw_map_wall(t_game *game, unsigned map_x, unsigned map_y)
{
	t_texture		*t;
	int				sides;

	sides = 0;
	if (map_y != 0 && game->map[map_y - 1][map_x] == '1')
		sides |= WALL_TOP;
	if (map_x + 1 != game->width && game->map[map_y][map_x + 1] == '1')
		sides |= WALL_RIGHT;
	if (map_y + 1 != game->height && game->map[map_y + 1][map_x] == '1')
		sides |= WALL_BOTTOM;
	if (map_x != 0 && game->map[map_y][map_x - 1] == '1')
		sides |= WALL_LEFT;
	t = choose_wall_texture(game, sides);
	if (!t)
		t = &(game->textures.wall_all);
	if (t)
		draw(game, t->image,
			map_x * game->part_width + game->padding_rl,
			map_y * game->part_height + game->padding_tb);
}

void	draw_map_exit(t_game *game, t_object *o)
{
	t_texture		*t;

	t = (t_texture *) o->texture->content;
	draw(game, t->image,
		o->map_x * game->part_width + game->padding_rl,
		o->map_y * game->part_height + game->padding_tb);
}
