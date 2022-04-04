/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 18:35:32 by alcierra          #+#    #+#             */
/*   Updated: 2022/04/04 22:36:57 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*point;

	if (argc != 2)
	{
		write(2, "Arguments Error\n", 17);
		return (0);
	}
	point = ft_strchr(argv[1], '.');
	if (point == NULL)
	{
		write(2, "Map file error: there is no extention\n", 39);
		return (0);
	}
	if (ft_strncmp(point + 1, "ber", 4) != 0)
	{
		write(2, "Map file error: file extention not .ber\n", 41);
		return (0);
	}
	ft_parse(argv[1]);
}
