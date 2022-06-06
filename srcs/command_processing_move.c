/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_processing_move.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 00:00:00 by alcierra          #+#    #+#             */
/*   Updated: 2022/05/22 11:28:13 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	delete_collectable(t_game *game, unsigned int x, unsigned int y)
{
	t_list		*list;
	t_list		*prev;
	t_object	*o;

	prev = NULL;
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
			ft_lstdelone(list, free);
			break ;
		}
		prev = list;
		list = list->next;
	}
}

static void	command_processing_move_post(t_game *game, unsigned int x,
											unsigned int y)
{
	t_list		*list;

	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = '0';
		delete_collectable(game, x, y);
		if (!game->collectibles)
		{
			list = game->exits;
			while (list)
			{
				((t_object *) list->content)->state = EXIT_TRANSITION;
				((t_object *) list->content)->texture = game->textures.exits_transition;
				list = list->next;
			}
		}
	}
	else if (game->map[y][x] == 'E')
	{
		game->endtext = "You Win!";
		mlx_key_hook(game->mlx_win, NULL, game);
		mlx_loop_hook(game->mlx, moment_processing_over, game);
	}
	else if (game->map[y][x] == 'D')
	{
		game->current_player->state = CHARACTER_DIED | CHARACTER_RUN;
		if (!game_condition_has_alive(game))
		{
			game->endtext = "You are Lose!";
			mlx_key_hook(game->mlx_win, NULL, game);
			mlx_loop_hook(game->mlx, moment_processing_over, game);
		}
	}
}

t_list		*command_processing_move_pre(t_game *game, t_player *player,
										int move, unsigned int *cords)
{
	t_list		*t;

	cords[0] = player->map_x;
	if (move & CHARACTER_RIGHT)
		cords[0] += 1;
	else if (move & CHARACTER_LEFT)
		cords[0] -= 1;
	cords[1] = player->map_y;
	if (move & CHARACTER_UP)
		cords[1] -= 1;
	else if (move & CHARACTER_DOWN)
		cords[1] += 1;
	t = NULL;
	if (move & CHARACTER_RIGHT)
		t = game->textures.players_right;
	else if (move & CHARACTER_LEFT)
		t = game->textures.players_left;
	else if (move & CHARACTER_UP)
		t = game->textures.players_up;
	else if (move & CHARACTER_DOWN)
		t = game->textures.players_down;
	return (t);
}

/*
t_list		*command_processing_move_pre(t_game *game, t_player *player,
								int move, unsigned int *cords)
{
	t_list		*t;

	t = NULL;
	cords[0] = player->map_x;
	if (move & CHARACTER_RIGHT)
	{
		cords[0] += 1;
		t = game->textures.players_right;
	}
	else if (move & CHARACTER_LEFT)
	{
		cords[0] -= 1;
		t = game->textures.players_left;
	}
	cords[1] = player->map_y;
	if (move & CHARACTER_UP)
	{
		cords[1] -= 1;
		t = game->textures.players_up;
	}
	else if (move & CHARACTER_DOWN)
	{
		cords[1] += 1;
		t = game->textures.players_down;
	}
	return (t);
}
*/

static void	command_processing_move_(t_game *game, t_player *player,
								int move, unsigned int *cords)
{
	unsigned int	i;
	unsigned int	count;
	t_state			*state;
	t_list			*list;
	t_list			*t;
	unsigned int	actual_x;
	unsigned int	actual_y;

	t = command_processing_move_pre(game, player, move, cords);
	count = ft_lstsize(t);
	i = 0;
	while (i < count)
	{
		actual_x = cords[0] * game->part_width + game->padding_rl;
		actual_y = cords[1] * game->part_height + game->padding_rl;
		if (move & CHARACTER_LEFT)
			actual_x += game->part_width / (count - i);
		if (move & CHARACTER_RIGHT)
			actual_x -= game->part_width / (count - i);
		if (move & CHARACTER_UP)
			actual_y += game->part_width / (count - i);
		else if (move & CHARACTER_DOWN)
			actual_y -= game->part_width / (count - i);
		state = create_state(actual_x, actual_y, (t_texture *) t->content);
		state->texture = (t_texture *) t->content;
		list = ft_lstnew(state);
		ft_lstadd_front(&(player->states), list);
		if (t->next)
			t = t->next;
		i++;
	}
}

void	command_processing_move(t_game *game, t_player *player, int move)
{
	unsigned int	cords[2];

	command_processing_move_pre(game, player, move, cords);
	if (is_player_can_move_to(game, cords[0], cords[1]))
	{
		command_processing_move_(game, player, move, cords);
		player->state = CHARACTER_RUN;
		player->map_next_x = cords[0];
		player->map_next_y = cords[1];
		command_processing_move_post(game, cords[0], cords[1]);
		game->moves++;
		if (game->after_move)
			game->after_move(game, game->moves);
	}
}
