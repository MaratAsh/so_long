/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_platform.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 12:07:25 by alcierra          #+#    #+#             */
/*   Updated: 2022/05/22 16:27:55 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_PLATFORM_H
# define SO_LONG_PLATFORM_H

# ifdef Darwin

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
# else

enum
{
	KEYBOARD_ESC = 65307,
	KEYBOARD_TAB = 65289,
	KEYBOARD_F5 = 65474,
	KEYBOARD_A = 97,
	KEYBOARD_S = 115,
	KEYBOARD_D = 100,
	KEYBOARD_W = 119,
	KEYBOARD_LEFT = 65361,
	KEYBOARD_RIGHT = 65363,
	KEYBOARD_UP = 65362,
	KEYBOARD_DOWN = 65364,
};
# endif

#endif
