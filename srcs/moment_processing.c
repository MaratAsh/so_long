//
// Created by Altagracia Cierra on 5/13/22.
//

#include "../so_long.h"


#include "../so_long.h"

void	process_animation_collectible(t_game *game, unsigned moment_id)
{
	t_list			*elem;
	t_object	*c;

	elem = game->collectibles;
	while (elem)
	{
		c = (t_object *) elem->content;
		if (c->change_moment == moment_id)
		{
			draw_map_background(c->map_x, c->map_y, game);
			if (c->texture->next)
				c->texture = c->texture->next;
			else
				c->texture = game->textures.coins;
			draw_map_collectible(game, c);
			c->change_moment += c->change_rate;
		}
		elem = elem->next;
	}
}

void	process_animation_player(t_game *game, t_player *p, unsigned moment_id)
{
	t_list			*next_list;

	(void) moment_id;

		if (p->state & CHARACTER_STAY)
		{
			draw_map_background(p->map_x, p->map_y, game);
			if (p->texture->next)
				p->texture = p->texture->next;
			else
				p->texture = game->textures.players;
			draw_map_player(game, p);
			p->change_moment += p->change_rate;
		}
		else if (p->state & CHARACTER_RUN)
		{
			next_list = p->states->next;
			if (p->map_next_x && p->map_next_y)
				draw_map_background(p->map_next_x, p->map_next_y, game);
			draw_map_player_state(game, p);
			draw_map_background(p->map_x, p->map_y, game);
			//ft_lstdelone(p->states, NULL);
			p->states = next_list;
			if (!next_list)
			{
				p->map_x = p->map_next_x;
				p->map_y = p->map_next_y;
				p->map_next_x = 0;
				p->map_next_y = 0;
				p->state = CHARACTER_STAY;
			}
		}
}

int	moment_processing(t_game *game)
{
	static unsigned	moment_id;

	if (moment_id % game->draw_rate == 0)
		ft_draw_all(game);
	process_animation_collectible(game, moment_id);
	process_animation_player(game, game->current_player, moment_id);
	moment_id++;
	return (0);
}
