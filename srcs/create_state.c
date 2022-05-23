/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_state.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:20:37 by alcierra          #+#    #+#             */
/*   Updated: 2022/05/23 21:20:50 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_state	*create_state(unsigned x, unsigned y, t_texture *texture)
{
	t_state		*state;

	state = ft_calloc(1, sizeof(t_state));
	state->started_moment = 0;
	state->rate = 5;
	state->texture = texture;
	state->x = x;
	state->y = y;
	return (state);
}
