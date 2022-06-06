/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_animation_exits.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:00:00 by alcierra          #+#    #+#             */
/*   Updated: 2022/05/18 24:00:00 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	process_animation_transition_exit(t_game *game, t_object *o,
											unsigned int moment_id)
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

void	process_animation_exit(t_game *game, t_object *o,
								unsigned int moment_id)
{
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
		process_animation_transition_exit(game, o, moment_id);
	}
}

void	process_animation_exits(t_game *game, unsigned int moment_id)
{
	t_list	*list;

	list = game->exits;
	while (list)
	{
		process_animation_exit(game, (t_object *) list->content, moment_id);
		list = list->next;
	}
}
