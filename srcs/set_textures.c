/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 18:35:32 by alcierra          #+#    #+#             */
/*   Updated: 2022/04/12 21:25:51 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_textures(t_game *game)
{
	t_object	*collectible;
	t_player		*p;
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
