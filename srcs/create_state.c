//
// Created by Altagracia Cierra on 5/19/22.
//

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
