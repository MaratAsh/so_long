# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/20 14:26:34 by alcierra          #+#    #+#              #
#    Updated: 2022/03/23 13:37:39 by alcierra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	get_next_line.a
HEADER	=	get_next_line.h
SRCS	=	get_next_line.c get_next_line_utils.c
OBJS	=	${SRCS:.c=.o}

all: $(NAME)

${NAME}: ${OBJS} ${HEADER}
		ar rcs $(NAME) $?

%.o : %.c ${HEADER}
		gcc -o $@ -c $<

clean:
		rm -rf ${OBJS}
fclean: clean
		rm -rf ${NAME}

print-%  : ; @echo $* = $($*)
