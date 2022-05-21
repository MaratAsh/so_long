/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:00:00 by alcierra          #+#    #+#             */
/*   Updated: 2022/05/20 20:02:43 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_texture	*choose_wall_texture(t_game *game, int sides)
{
	t_texture	*t;

	t = &(game->textures.wall_all);
	if (sides == WALL_NO)
		t = &(game->textures.wall_no);
	else if (sides == WALL_TR)
		t = &(game->textures.wall_tr);
	else if (sides == WALL_BL)
		t = &(game->textures.wall_bl);
	else if (sides == WALL_RBL || sides == WALL_RL)
		t = &(game->textures.wall_rbl);
	else if (sides == WALL_RB)
		t = &(game->textures.wall_rb);
	else if (sides == WALL_TRB || sides == WALL_TB)
		t = &(game->textures.wall_trb);
	else if (sides == WALL_TL)
		t = &(game->textures.wall_tl);
	else if (sides == WALL_RIGHT)
		t = &(game->textures.wall_r);
	else if (sides == WALL_LEFT)
		t = &(game->textures.wall_l);
	else if (sides == WALL_TRL || sides == WALL_RL)
		t = &(game->textures.wall_trl);
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
		draw(game, t->image, map_x * game->part_width,
			map_y * game->part_height);
}
