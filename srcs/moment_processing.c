/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moment_processing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:00:00 by alcierra          #+#    #+#             */
/*   Updated: 2022/05/18 24:00:00 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	process_animation_collectible(t_game *game, unsigned int moment_id)
{
	t_list		*elem;
	t_object	*c;

	elem = game->collectibles;
	while (elem)
	{
		c = (t_object *) elem->content;
		if (c->change_moment == moment_id)
		{
			draw_map_background(c->map_x, c->map_y, game);
			if (c->texture->next)
				c->texture = c->texture->next;
			else
				c->texture = game->textures.coins;
			draw_map_collectible(game, c);
			c->change_moment += c->change_rate;
		}
		elem = elem->next;
	}
}

void	process_animation_enemies(t_game *game, unsigned int moment_id)
{
	t_list		*elem;
	t_player	*e;

	elem = game->enemies;
	while (elem)
	{
		e = (t_player *) elem->content;
		if (e->change_moment == moment_id)
		{
			draw_map_background(e->map_x, e->map_y, game);
			draw_map_player(game, e);
			e->texture = e->texture->next;
			if (!e->texture)
				e->texture = game->textures.enemies;
			e->change_moment += e->change_rate;
		}
		elem = elem->next;
	}
}

int	moment_processing(t_game *game)
{
	static unsigned int	moment_id;

	if (moment_id % game->draw_rate == 0)
		ft_draw_all(game);
	process_animation_collectible(game, moment_id);
	process_animation_player(game, game->current_player, moment_id);
	process_animation_enemies(game, moment_id);
	process_animation_exits(game, moment_id);
	moment_id++;
	return (0);
}
