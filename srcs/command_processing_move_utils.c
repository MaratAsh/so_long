/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_processing_move_utils.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 00:00:00 by alcierra          #+#    #+#             */
/*   Updated: 2022/05/22 11:28:13 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_list	*get_texture_by_move(t_game *game, int move)
{
	if (move & CHARACTER_RIGHT)
		return (game->textures.players_right);
	else if (move & CHARACTER_LEFT)
		return (game->textures.players_left);
	else if (move & CHARACTER_UP)
		return (game->textures.players_up);
	else if (move & CHARACTER_DOWN)
		return (game->textures.players_down);
	return (NULL);
}

t_list	*command_processing_move_pre(t_game *game, t_player *player,
			int move, unsigned int *cords)
{
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
	return (get_texture_by_move(game, move));
}

void	state_to_player(t_player *player, unsigned int actual_x,
						unsigned int actual_y, t_list *t)
{
	t_state	*state;
	t_list	*list;

	state = create_state(actual_x, actual_y, (t_texture *) t->content);
	state->texture = (t_texture *) t->content;
	list = ft_lstnew(state);
	ft_lstadd_front(&(player->states), list);
}

void	command_processing_move_moment(t_game *game, t_player *player,
								int move, unsigned int *cords)
{
	unsigned int	i;
	unsigned int	count;
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
		state_to_player(player, actual_x, actual_y, t);
		t = t->next;
		i++;
	}
}
