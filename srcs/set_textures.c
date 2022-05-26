/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 18:35:32 by alcierra          #+#    #+#             */
/*   Updated: 2022/05/23 21:28:34 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	set_textures_players(t_game *game)
{
	t_player	*p;
	t_list		*list;

	list = game->players;
	while (list)
	{
		if (list->content)
		{
			p = (t_player *) list->content;
			p->texture = game->textures.players;
		}
		list = list->next;
	}
}

static void	set_textures_exits(t_game *game)
{
	t_list	*list;

	list = game->exits;
	while (list)
	{
		if (list->content)
		{
			((t_object *) list->content)->texture = game->textures.exits_close;
		}
		list = list->next;
	}
}

static void	set_textures_enemies(t_game *game)
{
	t_player	*p;
	t_list		*list;

	list = game->enemies;
	while (list)
	{
		if (list->content)
		{
			p = (t_player *) list->content;
			p->texture = game->textures.enemies;
		}
		list = list->next;
	}
}

void	set_textures(t_game *game)
{
	t_object		*collectible;
	t_list			*list;

	list = game->collectibles;
	while (list)
	{
		if (list->content)
		{
			collectible = (t_object *) list->content;
			collectible->texture = game->textures.coins;
		}
		list = list->next;
	}
	set_textures_players(game);
	set_textures_exits(game);
	set_textures_enemies(game);
}
