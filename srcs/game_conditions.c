/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_conditions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 00:00:00 by alcierra          #+#    #+#             */
/*   Updated: 2022/05/19 24:00:00 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_object	*get_exit(t_game *game, unsigned map_x, unsigned map_y)
{
	t_list	*list;

	list = game->exits;
	while (list)
	{
		if (((t_object *) list->content)->map_x == map_x
			&& ((t_object *) list->content)->map_y == map_y)
			return ((t_object *) list->content);
		list = list->next;
	}
	return (NULL);
}

int	is_player_can_move_to(t_game *game, unsigned int x, unsigned int y)
{
	t_list		*l;
	t_player	*p;

	if (game->current_player->state & CHARACTER_RUN
		|| game->current_player->state & CHARACTER_DIED)
		return (0);
	l = game->players;
	while (l)
	{
		p = (t_player *) l->content;
		if (p->map_x == x && p->map_y == y && p->state & CHARACTER_STAY)
			return (0);
		l = l->next;
	}
	if (game->map[y][x] == '0' || game->map[y][x] == 'C'
		|| game->map[y][x] == 'D')
		return (1);
	if (game->map[y][x] == 'E')
	{
		if (get_exit(game, x, y)->state == EXIT_OPEN)
			return (1);
	}
	return (0);
}

int	game_condition_has_alive(t_game *game)
{
	t_list		*list;
	t_player	*p;

	list = game->players;
	while (list)
	{
		p = (t_player *) list->content;
		if (!(p->state & CHARACTER_DIED))
			return (1);
		list = list->next;
	}
	return (0);
}
