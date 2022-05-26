/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 18:35:32 by alcierra          #+#    #+#             */
/*   Updated: 2022/04/12 21:25:51 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	load_texture(t_game *game, struct s_texture *t, char *path)
{
	t->image = mlx_xpm_file_to_image(game->mlx, path,
			&(t->width), &(t->height));
}

static void	load_obj_textures_loop(t_game *g, int i, char *s_path, t_texture *t)
{
	char		*temp;
	char		*temp_1;

	temp = ft_itoa(i);
	temp_1 = ft_strjoin(temp, ".xpm");
	free(temp);
	temp = ft_strjoin(s_path, temp_1);
	load_texture(g, t, temp);
	free(temp);
	free(temp_1);
}

static void	load_obj_textures(t_game *game, t_list **list, char *search_path)
{
	int			i;
	t_texture	*tptr;
	t_texture	t;
	t_list		*l;

	i = 0;
	while (1)
	{
		load_obj_textures_loop(game, i, search_path, &t);
		if (!t.image)
			break ;
		tptr = ft_calloc(1, sizeof(t_texture));
		if (!tptr)
			ft_error("Error: Malloc: cannot allocate memory for texture\n");
		ft_memcpy(tptr, &t, sizeof(t_texture));
		l = ft_lstnew(tptr);
		if (!l)
			ft_error("Error: Malloc: cannot allocate memory for texture list\n");
		ft_lstadd_back(list, l);
		i++;
	}
}

static void	load_textures_2(t_game *game)
{
	load_obj_textures(game, &(game->textures.coins),
		"./textures/coin/");
	load_obj_textures(game, &(game->textures.players),
		"./textures/player/notactive/");
	load_obj_textures(game, &(game->textures.players_left),
		"./textures/player/left/");
	load_obj_textures(game, &(game->textures.players_right),
		"./textures/player/right/");
	load_obj_textures(game, &(game->textures.players_down),
		"./textures/player/down/");
	load_obj_textures(game, &(game->textures.players_up),
		"./textures/player/up/");
	load_obj_textures(game, &(game->textures.enemies),
					  "./textures/enemy/notactive/");
	load_obj_textures(game, &(game->textures.exits_close),
		"./textures/exit/close/");
	load_obj_textures(game, &(game->textures.exits_open),
		"./textures/exit/open/");
	load_obj_textures(game, &(game->textures.exits_transition),
		"./textures/exit/trans/");
}

void	load_textures(t_game *game)
{
	load_texture(game, &(game->textures.background),
		"./textures/background.xpm");
	load_texture(game, &(game->textures.wall_all), "./textures/wall/all.xpm");
	load_texture(game, &(game->textures.wall_tr), "./textures/wall/tr.xpm");
	load_texture(game, &(game->textures.wall_trb), "./textures/wall/trb.xpm");
	load_texture(game, &(game->textures.wall_tbl), "./textures/wall/tbl.xpm");
	load_texture(game, &(game->textures.wall_trl), "./textures/wall/trl.xpm");
	load_texture(game, &(game->textures.wall_rl), "./textures/wall/rl.xpm");
	load_texture(game, &(game->textures.wall_tb), "./textures/wall/tb.xpm");
	load_texture(game, &(game->textures.wall_b), "./textures/wall/b.xpm");
	load_texture(game, &(game->textures.wall_tl),
		"./textures/wall/tl.xpm");
	load_texture(game, &(game->textures.wall_rb), "./textures/wall/rb.xpm");
	load_texture(game, &(game->textures.wall_rbl), "./textures/wall/rbl.xpm");
	load_texture(game, &(game->textures.wall_bl), "./textures/wall/bl.xpm");
	load_texture(game, &(game->textures.wall_r), "./textures/wall/r.xpm");
	load_texture(game, &(game->textures.wall_l), "./textures/wall/l.xpm");
	load_texture(game, &(game->textures.wall_t), "./textures/wall/t.xpm");
	load_texture(game, &(game->textures.wall_no), "./textures/wall/no.xpm");
	load_texture(game, &(game->textures.unknown), "./textures/unknown.xpm");
	load_textures_2(game);
}
