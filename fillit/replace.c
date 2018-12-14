/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:26:49 by maginist          #+#    #+#             */
/*   Updated: 2018/12/07 11:22:11 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**replace(char **tab, int y, int x, char **grid)
{
	int	i;
	int	j;
	int	sk;

	i = 0;
	sk = 0;
	while (tab[i] && grid[i + y])
	{
		j = 0;
		while (j < 4 && grid[i + y][j + x] && tab[i][j])
		{
			if (tab[i][j] != '.' && grid[i + y][j + x] != '.')
				return (0);
			if (grid[i + y][j + x] == '.' && tab[i][j] != '.')
			{
				sk++;
				grid[i + y][j + x] = tab[i][j];
			}
			if (sk == 4)
				return (grid);
			j++;
		}
		i++;
	}
	return (0);
}
