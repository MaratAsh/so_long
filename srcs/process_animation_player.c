/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_animation_player.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 00:00:00 by alcierra          #+#    #+#             */
/*   Updated: 2022/05/27 11:28:13 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	process_animation_run_player(t_game *game, t_player *p,
								unsigned int moment_id)
{
	t_list	*next_list;

	(void) moment_id;
	next_list = p->states->next;
	if (p->map_next_x && p->map_next_y)
		draw_map_background(p->map_next_x, p->map_next_y, game);
	draw_map_player_state(game, p);
	draw_map_background(p->map_x, p->map_y, game);
	ft_lstdelone(p->states, free);
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

void	process_animation_player(t_game *game, t_player *p,
								unsigned int moment_id)
{
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
		process_animation_run_player(game, p, moment_id);
	}
}
