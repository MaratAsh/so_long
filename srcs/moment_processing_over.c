/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moment_processing_over.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 00:00:00 by alcierra          #+#    #+#             */
/*   Updated: 2022/05/23 21:15:13 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	moment_processing_over(t_game *game)
{
	static unsigned int	moment;

	if (moment < 100)
		moment_processing(game);
	else
		ft_draw_all(game);
	ft_draw_all(game);
	if (game->endtext)
		mlx_string_put(game->mlx, game->mlx_win,
			game->width * game->part_width / 2,
			game->height * game->part_height / 2,
			0xFFFFFF, game->endtext);
	if (moment > 200)
	{
		ft_putstr_fd("\r                    \r", 1);
		ft_putendl_fd(game->endtext, 1);
		exit(0);
	}
	moment++;
	return (0);
}
