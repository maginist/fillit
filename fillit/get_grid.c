/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:15:16 by maginist          #+#    #+#             */
/*   Updated: 2018/12/07 14:47:15 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**get_grid(int size)
{
	char	**grid;
	int		i;

	i = 0;
	if (!(grid = (char**)ft_memalloc(sizeof(char*) * (size + 1))))
		exit(0);
	while (i < size)
	{
		if (!(grid[i] = (char*)malloc(sizeof(char) * (size + 1))))
			exit(0);
		ft_memset(grid[i], '.', size);
		grid[i][size] = '\0';
		i++;
	}
	grid[i] = 0;
	return (grid);
}
