/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moment_processing_move.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 00:00:00 by alcierra          #+#    #+#             */
/*   Updated: 2022/05/19 24:00:00 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../so_long.h"

static void	command_processing_move_post(t_game *game, unsigned x, unsigned y)
{
	t_list		*list;
	t_list		*prev;
	t_object	*o;

	prev = NULL;
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = '0';
		list = game->collectibles;
		while (list)
		{
			o = (t_object *) list->content;
			if (o->map_x == x && o->map_y == y)
			{
				if (prev)
				prev->next = list->next;
				else
					game->collectibles = list->next;
				/// TODO Leak possible. Need to check with leaks
				ft_lstdelone(list, free);
				break;
			}
			prev = list;
			list = list->next;
		}
	}
}

void	command_processing_move(t_game *game, t_player *player, int move)
{
	unsigned	to_x;
	unsigned	to_y;
	t_state		*state;
	t_list		*list;
	t_list		*t;
	unsigned	i;
	unsigned	count;

	t = NULL;
	if (move & CHARACTER_RIGHT)
	{
		to_x = player->map_x + 1;
		t = game->textures.players_right;
	}
	else if (move & CHARACTER_LEFT)
	{
		to_x = player->map_x - 1;
		t = game->textures.players_left;
	}
	else
		to_x = player->map_x;
	if (move & CHARACTER_UP)
	{
		to_y = player->map_y - 1;
		t = game->textures.players_up;
	}
	else if (move & CHARACTER_DOWN)
	{
		to_y = player->map_y + 1;
		t = game->textures.players_down;
	}
	else
		to_y = player->map_y;
	if (is_player_can_move_to(game, to_x, to_y))
	{
		player->state = CHARACTER_RUN | CHARACTER_UP;
		player->map_next_x = to_x;
		player->map_next_y = to_y;
		i = 0;
		count = ft_lstsize(t);
		while (i < count)
		{
			unsigned actual_x, actual_y;
			actual_x = to_x * game->part_width;
			actual_y = to_y * game->part_height;
			if (move & CHARACTER_LEFT)
				actual_x += game->part_width / (count - i);
			if (move & CHARACTER_RIGHT)
				actual_x -= game->part_width / (count - i);
			if (move & CHARACTER_UP)
				actual_y += game->part_width / (count - i);
			else if (move & CHARACTER_DOWN)
				actual_y -= game->part_width / (count - i);
			state = create_state(
					actual_x,
					actual_y,
					(t_texture *) t->content);
			state->texture = (t_texture *) t->content;
			list = ft_lstnew(state);
			ft_lstadd_front(&(player->states), list);
			if (t->next)
				t = t->next;
			i++;
		}
	}
	command_processing_move_post(game, to_x, to_y);
}
