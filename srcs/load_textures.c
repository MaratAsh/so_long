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
									 &(t->width),&(t->height));
}

static void	load_obj_textures(t_game *game, t_list **list, char *search_path)
{
	int			i;
	char		*temp;
	char 		*temp_1;
	t_texture	*tptr;
	t_texture	t;
	t_list		*l;

	i = 0;
	while (1)
	{
		temp = ft_itoa(i);
		temp_1 = ft_strjoin(temp, ".xpm");
		free(temp);
		temp = ft_strjoin(search_path, temp_1);
		load_texture(game, &t, temp);
		free(temp);
		free(temp_1);
		if (!t.image)
			break;
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

void	load_textures(t_game *game)
{
	load_texture(game, &(game->textures.background), "./textures/background.xpm");
	load_texture(game, &(game->textures.border_all), "./textures/border_trbl.xpm");
	load_texture(game, &(game->textures.unknown), "./textures/unknown.xpm");
	load_obj_textures(game, &(game->textures.coins), "./textures/coin/");
	load_obj_textures(game, &(game->textures.players), "./textures/player/notactive/");
	load_obj_textures(game, &(game->textures.players_left), "./textures/player/left/");
	load_obj_textures(game, &(game->textures.players_right), "./textures/player/right/");
	load_obj_textures(game, &(game->textures.players_down), "./textures/player/down/");
	load_obj_textures(game, &(game->textures.players_up), "./textures/player/up/");
	load_obj_textures(game, &(game->textures.exits_close), "./textures/exit/close/");
	load_obj_textures(game, &(game->textures.exits_open), "./textures/exit/open/");
}
