//
// Created by Altagracia Cierra on 5/13/22.
//

#include "../so_long.h"


void	command_processing_change_player(t_game *game)
{
	t_list	*l;

	l = game->players;
	while (l)
	{
		if (game->current_player == l->content)
		{
			if (l->next)
			{
				game->current_player = (t_player *) l->next->content;
				break;
			}
			else
				game->current_player = NULL;
		}
		l = l->next;
	}
	if (!game->current_player)
		game->current_player = (t_player *) game->players->content;
}

int	command_processing(int keycode, t_game *game)
{
	if (keycode == KEYBOARD_ESC)
		exit(0);
	else if (keycode == KEYBOARD_W || keycode == KEYBOARD_UP)
		command_processing_move(game, game->current_player, CHARACTER_UP);
	else if (keycode == KEYBOARD_S || keycode == KEYBOARD_DOWN)
		command_processing_move(game, game->current_player, CHARACTER_DOWN);
	else if (keycode == KEYBOARD_A || keycode == KEYBOARD_LEFT)
		command_processing_move(game, game->current_player, CHARACTER_LEFT);
	else if (keycode == KEYBOARD_D || keycode == KEYBOARD_RIGHT)
		command_processing_move(game, game->current_player, CHARACTER_RIGHT);
	else if (keycode == KEYBOARD_TAB)
	{
		command_processing_change_player(game);
		ft_draw_all(game);
	}
	else if (keycode == KEYBOARD_F5)
		ft_draw_all(game);
	return (0);
}
