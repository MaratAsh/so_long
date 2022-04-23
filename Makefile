# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alcierra <alcierra@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/04 17:10:25 by alcierra          #+#    #+#              #
#    Updated: 2022/04/04 22:42:50 by alcierra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
HEADER	=	so_long.h

FLDR_S	=	srcs/
FLDR_O	=	objs/

SRCS	=	ft_parse.c			ft_map_check.c			ft_error.c		\
			ft_draw_all.c

OBJS	=	${SRCS:.c=.o}

SRCS_WD	=	$(addprefix ${FLDR_S},${SRCS})
OBJS_WD	=	$(addprefix ${FLDR_O},${OBJS})

FLAGS	=	-Wall -Wextra -Werror

LIB_INCL	=	./libft/libft.a
MLX_INCL	=	./minilibx/libmlx.a
LIB_MAKE	=	make -C $(dir $(LIB_INCL))
MLX_MAKE	=	make -C $(dir $(MLX_INCL))

all: lib $(FLDR_O) $(NAME)

$(LIB_INCL):
		${LIB_MAKE} all

$(MLX_INCL):
		${MLX_MAKE} all

lib: $(LIB_INCL) $(MLX_INCL)

$(FLDR_O):
		mkdir $(FLDR_O)

$(NAME): ${FLDR_O}main.o ${OBJS_WD} ${HEADER}
		${CC} $(OBJS_WD) ${FLDR_O}main.o -framework OpenGL -framework AppKit -o $(NAME) -I. $(LIB_INCL) -I. $(MLX_INCL)

clean:
		${LIB_MAKE} clean
		${MLX_MAKE} clean
		rm -rf ${FLDR_O}main.o ${OBJS_WD} ${OBJS_B_WD}

fclean:
		${LIB_MAKE} fclean
		${MLX_MAKE} clean
		rm -rf ${FLDR_O}main.o ${OBJS_WD} ${OBJS_B_WD} ${NAME}

${FLDR_O}%.o : ${FLDR_S}%.c ${HEADER}
		gcc ${FLAGS} -Imlx -c $< -o $@

${FLDR_O}%.o : %.c ${HEADER}
		gcc ${FLAGS} -Imlx -c $< -o $@

re: fclean all

bonus: lib main-bonus.o ${OBJS_WD} ${HEADER}
		@make OBJS_WD="$(OBJS_B_WD)" all

.PHONY: all clean fclean re	bonus

