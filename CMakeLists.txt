cmake_minimum_required(VERSION 3.21)
project(so_long C)

include_directories(/usr/local/include/)

set(CMAKE_C_STANDARD 99)

include_directories(libft)
include_directories(minilibx)

add_library(ft STATIC
        libs/libft/srcs/ft_isalpha.c
        libs/libft/srcs/ft_isdigit.c
        libs/libft/srcs/ft_isalnum.c
        libs/libft/srcs/ft_isascii.c
        libs/libft/srcs/ft_isprint.c
        libs/libft/srcs/ft_strlen.c
        libs/libft/srcs/ft_memset.c
        libs/libft/srcs/ft_bzero.c
        libs/libft/srcs/ft_memcpy.c
        libs/libft/srcs/ft_memmove.c
        libs/libft/srcs/ft_strlcpy.c
        libs/libft/srcs/ft_strlcat.c
        libs/libft/srcs/ft_toupper.c
        libs/libft/srcs/ft_tolower.c
        libs/libft/srcs/ft_strchr.c
        libs/libft/srcs/ft_strrchr.c
        libs/libft/srcs/ft_strncmp.c
        libs/libft/srcs/ft_memchr.c
        libs/libft/srcs/ft_memcmp.c
        libs/libft/srcs/ft_strnstr.c
        libs/libft/srcs/ft_atoi.c
        libs/libft/srcs/ft_calloc.c
        libs/libft/srcs/ft_strdup.c
        libs/libft/srcs/ft_substr.c
        libs/libft/srcs/ft_strjoin.c
        libs/libft/srcs/ft_strtrim.c
        libs/libft/srcs/ft_split.c
        libs/libft/srcs/ft_itoa.c
        libs/libft/srcs/ft_strmapi.c
        libs/libft/srcs/ft_striteri.c
        libs/libft/srcs/ft_putchar_fd.c
        libs/libft/srcs/ft_putstr_fd.c
        libs/libft/srcs/ft_putendl_fd.c
        libs/libft/srcs/ft_putnbr_fd.c
        libs/libft/srcs/ft_split_inline.c

        libs/libft/srcs/ft_lstadd_back_bonus.c
        libs/libft/srcs/ft_lstadd_front_bonus.c
        libs/libft/srcs/ft_lstclear_bonus.c
        libs/libft/srcs/ft_lstdelone_bonus.c
        libs/libft/srcs/ft_lstiter_bonus.c
        libs/libft/srcs/ft_lstlast_bonus.c
        libs/libft/srcs/ft_lstmap_bonus.c
        libs/libft/srcs/ft_lstnew_bonus.c
        libs/libft/srcs/ft_lstsize_bonus.c
        )

add_library(mlx STATIC
        libs/minilibx/mlx_shaders.c
        libs/minilibx/mlx_new_window.m
        libs/minilibx/mlx_init_loop.m
        libs/minilibx/mlx_new_image.m
        libs/minilibx/mlx_xpm.c
        libs/minilibx/mlx_int_str_to_wordtab.c
        libs/minilibx/mlx_png.c
        libs/minilibx/mlx_mouse.m
        )

add_executable(so_long
        main.c
        srcs/ft_game_set.c srcs/ft_parse_map_file.c srcs/ft_map_check.c srcs/ft_error.c srcs/ft_draw_all.c
        srcs/load_textures.c srcs/command_processing.c srcs/moment_processing.c
        srcs/set_textures.c srcs/draw.c srcs/command_processing_move.c srcs/create_state.c srcs/game_conditions.c
        )

target_link_libraries(so_long ft)
target_link_libraries(so_long mlx "-framework OpenGL" "-framework AppKit")
