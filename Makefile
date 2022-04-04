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

SRCS	=	ft_parse.c			

OBJS	=	${SRCS:.c=.o}

SRCS_WD	=	$(addprefix ${FLDR_S},${SRCS})
OBJS_WD	=	$(addprefix ${FLDR_O},${OBJS})

FLAGS	=	-Wall -Wextra -Werror

LIB_INCL	=	./libft/libft.a
LIB_MAKE	=	make -C $(dir $(LIB_INCL))
GNL_INCL	=	./get_next_line/get_next_line.a
GNL_MAKE	=	make -C $(dir $(GNL_INCL))

all: lib $(FLDR_O) $(NAME)

$(LIB_INCL):
		${LIB_MAKE} all

$(GNL_INCL):
		${GNL_MAKE} all

lib: $(LIB_INCL) $(GNL_INCL)

$(FLDR_O):
		mkdir $(FLDR_O)

$(NAME): main.o ${OBJS_WD} ${HEADER}
		${CC} $(OBJS_WD) main.o -o $(NAME) -I. $(LIB_INCL) $(GNL_INCL)

clean:
		${LIB_MAKE} clean
		${GNL_MAKE} clean
		rm -rf main.o ${OBJS_WD} ${OBJS_B_WD}

fclean:
		${LIB_MAKE} fclean
		${GNL_MAKE} fclean
		rm -rf main.o ${OBJS_WD} ${OBJS_B_WD} ${NAME}

${FLDR_O}%.o : ${FLDR_S}%.c ${HEADER}
		gcc ${FLAGS} -c $< -o $@

%.o : %.c ${HEADER}
		gcc ${FLAGS} -c $< -o $@

re: fclean all

bonus: lib main-bonus.o ${OBJS_WD} ${HEADER}
		@make OBJS_WD="$(OBJS_B_WD)" all

.PHONY: all clean fclean re	bonus

