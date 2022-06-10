/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 18:35:32 by alcierra          #+#    #+#             */
/*   Updated: 2022/05/23 21:29:25 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	game_set_norm(t_game *game, unsigned int i, unsigned int j)
{
	t_list	*list;

	if (game->map[i][j] == 'P')
	{
		game->map[i][j] = '0';
		list = ft_lstnew(create_player(j, i));
		ft_lstadd_back(&(game->players), list);
	}
	else if (game->map[i][j] == 'C')
	{
		list = ft_lstnew(create_collectible(j, i));
		ft_lstadd_back(&(game->collectibles), list);
	}
	else if (game->map[i][j] == 'E')
	{
		list = ft_lstnew(create_exit(j, i));
		ft_lstadd_back(&(game->exits), list);
	}
	else if (game->map[i][j] == 'D')
	{
		list = ft_lstnew(create_player(j, i));
		ft_lstadd_back(&(game->enemies), list);
	}
}

void	ft_game_set(t_game *game)
{
	unsigned int	i;
	unsigned int	j;

	game->part_height = 100;
	game->part_width = 100;
	game->draw_rate = 1000;
	game->padding_tb = 10;
	game->padding_rl = 10;
	game->moves = 0;
	game->width = ft_strlen(game->map[0]);
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			game_set_norm(game, i, j);
			j++;
		}
		i++;
	}
	game->height = i;
	if (game->players)
		game->current_player = (t_player *) game->players->content;
}
