/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:22:00 by maginist          #+#    #+#             */
/*   Updated: 2018/12/07 13:56:06 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_delete(char **tab, int y, int x, char **grid)
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
			if (grid[i + y][j + x] == tab[i][j] && tab[i][j] != '.')
			{
				sk++;
				grid[i + y][j + x] = '.';
			}
			if (sk == 4)
				return (grid);
			j++;
		}
		i++;
	}
	return (0);
}
