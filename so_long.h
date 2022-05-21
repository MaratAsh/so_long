/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 18:35:32 by alcierra          #+#    #+#             */
/*   Updated: 2022/04/12 21:25:51 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libs/libft/libft.h"
# include <unistd.h>
# include <fcntl.h>

# include <stdio.h>
# include <math.h>

# include "libs/minilibx/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

# define MAP_EXACTLY_NOT_VALID 11

typedef struct s_texture
{
	void	*image;
	int		width;
	int		height;
}				t_texture;

typedef struct s_textures
{
	struct s_texture	background;
	t_list 				*coins;
	t_list 				*players;
	t_list 				*players_left;
	t_list 				*players_right;
	t_list 				*players_up;
	t_list 				*players_down;
	t_list 				*exits_open;
	t_list 				*exits_close;
	t_texture			wall_all;
	t_texture			wall_tr;
	t_texture			wall_trb;
	t_texture			wall_tbl;
	t_texture			wall_trl;
	t_texture			wall_tl;
	t_texture			wall_rl;
	t_texture			wall_rb;
	t_texture			wall_rbl;
	t_texture			wall_bl;
	t_texture			wall_tb;
	t_texture			wall_r;
	t_texture			wall_t;
	t_texture			wall_l;
	t_texture			wall_no;
	void	*exit_close;
	void	*exit_open;
	struct s_texture	unknown;
	void	*player;
}				t_textures;

typedef struct s_state
{
	unsigned	x;
	unsigned	y;
	unsigned	started_moment;
	unsigned	rate;
	t_texture	*texture;
}				t_state;

typedef struct s_player
{
	unsigned int 		map_x;
	unsigned int 		map_y;
	unsigned int 		map_next_x;
	unsigned int 		map_next_y;
	int 				state;
	unsigned int 		change_moment;
	unsigned int 		change_rate;
	t_list 				*states;
	t_list 				*texture;
}				t_player;

typedef struct s_collectible
{
	unsigned int 		map_x;
	unsigned int 		map_y;
	unsigned int 		change_moment;
	unsigned int 		change_rate;
	t_list 				*texture;
}				t_object;

typedef struct s_map
{
	char			**map;
	char			*str;
	unsigned int	width;
	unsigned int	height;
	unsigned int	moves;
	unsigned int	draw_rate;
	unsigned int	part_width;
	unsigned int	part_height;
	void			*mlx;
	void			*mlx_win;
	t_list 			*render;
	t_list 			*enemies;
	t_list 			*collectibles;
	t_list 			*players;
	t_player		*current_player;
	t_list 			*exits;
	t_textures		textures;
	void			(*after_move)(struct s_map *g, unsigned count);
}				t_game;

enum
{
	KEYBOARD_ESC = 53,
	KEYBOARD_TAB = 48,
	KEYBOARD_F5 = 96,
	KEYBOARD_A = 0,
	KEYBOARD_S = 1,
	KEYBOARD_D = 2,
	KEYBOARD_W = 13,
	KEYBOARD_LEFT = 123,
	KEYBOARD_RIGHT = 124,
	KEYBOARD_UP = 126,
	KEYBOARD_DOWN = 125,
};

enum
{
	CHARACTER_STAY = 1,
	CHARACTER_RUN = 2,

	CHARACTER_LEFT = 1024,
	CHARACTER_RIGHT = 2048,
	CHARACTER_UP = 4096,
	CHARACTER_DOWN = 8192,
};

enum
{
	WALL_ALL	= 0b1111,

	WALL_TOP	= 0b0001,
	WALL_RIGHT	= 0b0010,
	WALL_BOTTOM	= 0b0100,
	WALL_LEFT	= 0b1000,

	WALL_TRB	= 0b0111,
	WALL_TRL	= 0b1011,
	WALL_TBL	= 0b1101,
	WALL_RBL	= 0b1110,

	WALL_TR		= 0b0011,
	WALL_TB		= 0b0101,
	WALL_TL		= 0b1001,
	WALL_RB		= 0b0110,
	WALL_RL		= 0b1010,
	WALL_BL		= 0b1100,

	WALL_NO		= 0b0000,
};

int		ft_parse_map_file(char *map_file, t_game *game);
void	ft_game_set(t_game *game);
void	load_textures(t_game *game);
void	set_textures(t_game *game);
//t_game	*ft_parse(char *map_file, t_game *map);
void	ft_error(char *msg);
void	ft_map_check(t_game *game);
void	ft_draw_all(t_game *game);
int		command_processing(int keycode, t_game *game);
int		moment_processing(t_game *game);


void	draw(t_game *game, void *img, unsigned x, unsigned y);
void	draw_map_background(unsigned x, unsigned y, t_game *game);
void	draw_map_collectible(t_game *game, t_object *c);
void	draw_map_player(t_game *game, t_player *p);
void	draw_map_player_state(t_game *game, t_player *p);
void	draw_map_wall(t_game *game, unsigned map_x, unsigned map_y);

t_state	*create_state(unsigned x, unsigned y, t_texture *texture);

void	command_processing_move(t_game *game, t_player *player, int move);

// game_conditions.c
int 	is_player_can_move_to(t_game *game, unsigned int x, unsigned int y);

#endif
