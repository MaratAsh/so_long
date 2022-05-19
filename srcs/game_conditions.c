//
// Created by Altagracia Cierra on 5/19/22.
//


#include "../so_long.h"

int 	is_player_can_move_to(t_game *game, unsigned int x, unsigned int y)
{
	t_list		*l;
	t_player	*p;

	l = game->players;
	while (l)
	{
		p = (t_player *) l->content;
		if (p->map_x == x && p->map_y == y)
			return (0);
		l = l->next;
	}
	if (game->map[y][x] == '0' || game->map[y][x] == 'C')
		return (1);
	return (0);
}