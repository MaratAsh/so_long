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


void	process_animation_collectible(t_game *game, unsigned moment_id)
{
	t_list			*elem;
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

void	process_animation_player(t_game *game, t_player *p, unsigned moment_id)
{
	t_list			*next_list;

	(void) moment_id;

		if (p->state & CHARACTER_STAY)
		{
			draw_map_background(p->map_x, p->map_y, game);
			if (p->texture->next)
				p->texture = p->texture->next;
			else
				p->texture = game->textures.players;
			draw_map_player(game, p);
			p->change_moment += p->change_rate;
		}
		else if (p->state & CHARACTER_RUN)
		{
			next_list = p->states->next;
			if (p->map_next_x && p->map_next_y)
				draw_map_background(p->map_next_x, p->map_next_y, game);
			draw_map_player_state(game, p);
			draw_map_background(p->map_x, p->map_y, game);
			ft_lstdelone(p->states, NULL);
			p->states = next_list;
			if (!next_list)
			{
				p->map_x = p->map_next_x;
				p->map_y = p->map_next_y;
				p->map_next_x = 0;
				p->map_next_y = 0;
				if (p->state & CHARACTER_DIED)
					p->state = CHARACTER_DIED;
				else
					p->state = CHARACTER_STAY;
			}
		}
}

void	process_animation_exit(t_game *game, unsigned moment_id)
{
	t_list			*list;
	t_object		*o;

	(void) moment_id;
	list = game->exits;
	while (list)
	{
		o = (t_object *) list->content;
		if (o->state == EXIT_CLOSE || o->state == EXIT_OPEN)
		{
			if (o->change_moment == moment_id)
			{
				draw_map_background(o->map_x, o->map_y, game);
				if (o->texture->next)
					o->texture = o->texture->next;
				else if (o->state == EXIT_CLOSE)
					o->texture = game->textures.exits_close;
				else
					o->texture = game->textures.exits_open;
				draw_map_exit(game, o);
				o->change_moment += o->change_rate;
			}
		}
		else if (o->state == EXIT_TRANSITION)
		{
			if (o->change_moment == moment_id)
			{
				draw_map_background(o->map_x, o->map_y, game);
				draw_map_exit(game, o);
				o->texture = o->texture->next;
				if (!o->texture)
				{
					o->state = EXIT_OPEN;
					o->texture = game->textures.exits_open;

				}
				o->change_moment += o->change_rate;
			}

		}
		list = list->next;
	}

}

void	process_animation_enemies(t_game *game, unsigned moment_id)
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
			{
				e->texture = game->textures.enemies;
			}
			e->change_moment += e->change_rate;
		}
		elem = elem->next;
	}
}

int	moment_processing(t_game *game)
{
	static unsigned	moment_id;

	if (moment_id % game->draw_rate == 0)
		ft_draw_all(game);
	process_animation_collectible(game, moment_id);
	process_animation_player(game, game->current_player, moment_id);
	process_animation_enemies(game, moment_id);
	process_animation_exit(game, moment_id);
	moment_id++;
	return (0);
}
