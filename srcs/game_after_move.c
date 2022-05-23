/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_after_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 00:00:00 by alcierra          #+#    #+#             */
/*   Updated: 2022/05/23 21:18:13 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	game_after_move(struct s_map *g, unsigned int count)
{
	(void) g;
	ft_putstr_fd("\rMoves: ", 1);
	ft_putnbr_fd((int) count, 1);
}

void	game_after_move_graph(t_game *g, unsigned int count)
{
	char	*str;
	char	*str_num;

	str_num = ft_itoa((int) count);
	if (!str_num)
		return ;
	str = ft_strjoin("Moves: ", str_num);
	if (!str)
		return ;
	draw_map_wall(g, 0, 0);
	draw_map_wall(g, 1, 0);
	mlx_string_put(g->mlx, g->mlx_win, 0, (g->part_height - 30) / 2,
		0xFFFFFF, str);
	free(str_num);
	free(str);
}
