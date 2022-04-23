/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:02:02 by alcierra          #+#    #+#             */
/*   Updated: 2022/04/13 19:02:13 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*ft_get_img(t_map *map, int img_type)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = NULL;
	if (img_type == 1)
		img = mlx_xpm_file_to_image(map->mlx, "./textures/background.xpm",
									&img_width, &img_height);
	else if (img_type == 2)
		img = mlx_xpm_file_to_image(map->mlx, "./textures/collectible.xpm",
									&img_width, &img_height);
	else if (img_type == 3)
		img = mlx_xpm_file_to_image(map->mlx, "./textures/stone.xpm",
									&img_width, &img_height);
	else if (img_type == 4)
		img = mlx_xpm_file_to_image(map->mlx, "./textures/exit.xpm",
									&img_width, &img_height);
	else if (img_type == 5)
		img = mlx_xpm_file_to_image(map->mlx, "./textures/character.xpm",
									&img_width, &img_height);
	if (!img)
		img = mlx_xpm_file_to_image(map->mlx, "./textures/unknown.xpm",
								   &img_width, &img_height);
	return img;
}

void	ft_draw_by_char(t_map *map, unsigned int i, unsigned int j)
{
	void	*img;

	img = ft_get_img(map, 1);
	if (img)
		mlx_put_image_to_window(map->mlx, map->mlx_win, img, 100 * j, 100 * i);
	if (map->map[i][j] == 'C')
		img = ft_get_img(map, 2);
	else if (map->map[i][j] == '1')
		img = ft_get_img(map, 3);
	else if (map->map[i][j] == 'E')
		img = ft_get_img(map, 4);
	else if (ft_strchr("01P", map->map[i][j]) == NULL)
		img = ft_get_img(map, 0);
	else
		return;
	if (img)
		mlx_put_image_to_window(map->mlx, map->mlx_win, img, 100 * j, 100 * i);
}

void	ft_draw_all(t_map *map)
{
	void			*img;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < map->heigth)
	{
		j = 0;
		while (j < map->width)
		{
			ft_draw_by_char(map, i, j);
			j++;
		}
		i++;
	}
	img = ft_get_img(map, 5);
	if (img)
		mlx_put_image_to_window(map->mlx, map->mlx_win, img, 100 * map->character_x, 100 *
		map->character_y);
}
