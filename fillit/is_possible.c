/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_possible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:52:47 by maginist          #+#    #+#             */
/*   Updated: 2018/12/07 11:16:57 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	is_possible(char **tab, int y, int x, char **grid)
{
	int		i;
	int		j;
	int		sk;
	int		size;

	size = ft_strlen(grid[0]);
	i = 0;
	sk = 0;
	while (i < 4 && i + y < size && grid[i + y])
	{
		j = 0;
		while (j < 4 && j + x < size && grid[i + y][j + x] && tab[i][j])
		{
			if (tab[i][j] != '.' && grid[i + y][j + x] != '.')
				return (0);
			if (grid[i + y][j + x] == '.' && tab[i][j] != '.')
				sk++;
			if (sk == 4)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
