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

static void	open_exits(t_game *game)
{
	t_list	*list;

	list = game->exits;
	while (list)
	{
		((t_object *) list->content)->state = EXIT_TRANSITION;
		((t_object *) list->content)->texture = game->textures.exits_transition;
		list = list->next;
	}
}

static void	command_processing_move_post(t_game *game, unsigned int x,
											unsigned int y)
{
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = '0';
		delete_collectable(game, x, y);
		if (!game->collectibles)
			open_exits(game);
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
			game->endtext = "Game Over!";
			mlx_key_hook(game->mlx_win, NULL, game);
			mlx_loop_hook(game->mlx, moment_processing_over, game);
		}
	}
}

void	command_processing_move(t_game *game, t_player *player, int move)
{
	unsigned int	cords[2];

	command_processing_move_pre(game, player, move, cords);
	if (is_player_can_move_to(game, cords[0], cords[1]))
	{
		command_processing_move_moment(game, player, move, cords);
		player->state = CHARACTER_RUN;
		player->map_next_x = cords[0];
		player->map_next_y = cords[1];
		command_processing_move_post(game, cords[0], cords[1]);
		game->moves++;
		if (game->after_move)
			game->after_move(game, game->moves);
	}
}
