/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_create_objects.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 18:35:32 by alcierra          #+#    #+#             */
/*   Updated: 2022/05/27 21:29:25 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_object	*create_collectible(unsigned int x, unsigned int y)
{
	t_object	*ptr;

	ptr = ft_calloc(sizeof(t_object), 1);
	ptr->map_x = x;
	ptr->map_y = y;
	ptr->change_moment = 1;
	ptr->change_rate = 5 + rand() % 5;
	return (ptr);
}

t_object	*create_exit(unsigned int x, unsigned int y)
{
	t_object	*ptr;

	ptr = ft_calloc(sizeof(t_object), 1);
	ptr->map_x = x;
	ptr->map_y = y;
	ptr->change_moment = 1;
	ptr->change_rate = 5 + rand() % 5;
	ptr->state = EXIT_CLOSE;
	return (ptr);
}

t_player	*create_player(unsigned int x, unsigned int y)
{
	t_player	*ptr;

	ptr = ft_calloc(sizeof(t_player), 1);
	ptr->map_x = x;
	ptr->map_y = y;
	ptr->map_next_x = 0;
	ptr->map_next_y = 0;
	ptr->change_rate = 5;
	ptr->state = CHARACTER_STAY;
	return (ptr);
}
