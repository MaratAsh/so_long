# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/04 17:10:25 by alcierra          #+#    #+#              #
#    Updated: 2022/05/22 16:54:01 by alcierra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
NAME_B	=	so_long_bonus
HEADER	=	so_long.h	so_long_platform.h

FLDR_S	=	srcs/
FLDR_O	=	objs/

SRCS	=	ft_game_set.c			ft_map_check.c			ft_error.c		\
			ft_draw_all.c			ft_parse_map_file.c		load_textures.c	\
			command_processing.c	moment_processing.c		set_textures.c	\
			draw.c					command_processing_move.c				\
			create_state.c			game_conditions.c		draw_2.c		\
			game_after_move.c		moment_processing_over.c				\
			window.c				process_animation_player.c				\
			process_animation_exits.c		game_create_objects.c			\
			command_processing_move_utils.c

SRCS_B	=	map_check_bonus.c

OBJS	=	${SRCS:.c=.o}
OBJS_B	=	${SRCS_B:.c=.o}

SRCS_WD	=	$(addprefix ${FLDR_S},${SRCS})
OBJS_WD	=	$(addprefix ${FLDR_O},${OBJS})

SRCS_B_WD	=	$(addprefix ${FLDR_S},${SRCS_B})
OBJS_B_WD	=	$(addprefix ${FLDR_O},${OBJS_B})

FLAGS	=	-Wall -Wextra -Werror

LIB_INCL	=	./libs/libft/libft.a
MLX_INCL	=	./libs/minilibx/libmlx.a
LIB_MAKE	=	make -C $(dir $(LIB_INCL))
MLX_MAKE	=	make -C $(dir $(MLX_INCL))

ifeq ($(shell uname),Darwin)
	#MacOS stuff
	COMPILLER = ${CC} objectfiles -framework OpenGL -framework AppKit -I. $(LIB_INCL) -I. $(MLX_INCL)
	COMPILLERS = ${CC} -D Darwin=1 ${FLAGS} -Imlx
else
	#Linux stuff
	COMPILLER = $(CC) objectfiles -L./libs/minilibx -L./libs/libft -L/usr/lib -lmlx -lft -lXext -lX11 -lm -lz
	COMPILLERS = $(CC) -D Linux=1 ${FLAGS} -lmlx -lft -I/usr/include -Llibs/minilibx -Llibs/libft -O3
endif

all: lib $(FLDR_O) $(NAME)

$(LIB_INCL):
		${LIB_MAKE} bonus
		${LIB_MAKE} all

$(MLX_INCL):
		${MLX_MAKE} all

lib: $(LIB_INCL) $(MLX_INCL)

$(FLDR_O):
		mkdir $(FLDR_O)

$(NAME): ${FLDR_O}main.o ${OBJS_WD} ${HEADER}
		$(COMPILLER:objectfiles=$(OBJS_WD) ${FLDR_O}main.o) -o $(NAME)


$(NAME_B): ${FLDR_O}main_bonus.o ${OBJS_WD} ${OBJS_B_WD} ${HEADER}
		$(COMPILLER:objectfiles=$(OBJS_WD) $(OBJS_B_WD) ${FLDR_O}main_bonus.o) -o $(NAME_B)

clean:
		${LIB_MAKE} clean
		${MLX_MAKE} clean
		rm -rf ${FLDR_O}main.o ${OBJS_WD} ${OBJS_B_WD}

fclean:
		${LIB_MAKE} fclean
		${MLX_MAKE} clean
		rm -rf ${FLDR_O}main.o ${OBJS_WD} ${OBJS_B_WD} ${NAME} ${NAME_B}

${FLDR_O}%.o : ${FLDR_S}%.c ${HEADER}
		$(COMPILLERS) -c $< -o $@

${FLDR_O}%.o : %.c ${HEADER}
		$(COMPILLERS) -c $< -o $@

re: fclean all

bonus: lib $(FLDR_O) $(NAME_B)

.PHONY: all clean fclean re	bonus

