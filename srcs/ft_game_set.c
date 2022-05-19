/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 18:35:32 by alcierra          #+#    #+#             */
/*   Updated: 2022/04/12 21:25:51 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_object	*create_collectible(unsigned x, unsigned y)
{
	t_object	*ptr;

	ptr = ft_calloc(sizeof( t_object), 1);
	ptr->map_x = x;
	ptr->map_y = y;
	ptr->change_moment = 1;
	ptr->change_rate = 5 + rand() % 5;
	return (ptr);
}

t_object	*create_exit(unsigned x, unsigned y)
{
	t_object	*ptr;

	ptr = ft_calloc(sizeof( t_object), 1);
	ptr->map_x = x;
	ptr->map_y = y;
	ptr->change_moment = 1;
	ptr->change_rate = 5 + rand() % 5;
	return (ptr);
}

t_player	*create_player(unsigned x, unsigned y)
{
	t_player	*ptr;

	ptr = ft_calloc(sizeof(t_player), 1);
	ptr->map_x = x;
	ptr->map_y = y;
	ptr->map_next_x = 0;
	ptr->map_next_y = 0;
	ptr->state = CHARACTER_STAY;
	return (ptr);
}

void	ft_game_set(t_game *game)
{
	unsigned int	i;
	unsigned int	j;
	t_list			*list;

	game->part_height = 100;
	game->part_width = 100;
	game->draw_rate = 1000;
	game->width = ft_strlen(game->map[0]);
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->character_x = j;
				game->character_y = i;
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
			j++;
		}
		i++;
	}
	game->height = i;
	game->current_player = (t_player *) game->players->content;
}
