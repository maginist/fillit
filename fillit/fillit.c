/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:03:10 by maginist          #+#    #+#             */
/*   Updated: 2018/12/07 18:03:37 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		whos_next(int *y, int *x, int size)
{
	if (*x < size - 1)
		*x += 1;
	else
	{
		*x = 0;
		*y += 1;
	}
}

void			ft_init_coord(int *x, int *y)
{
	*x = 0;
	*y = 0;
}

static char		**end(int turn, char **grid)
{
	turn = 0;
	ft_tabdel(grid);
	return (0);
}

static char		**backtrack(char ***tab, char **grid, int i, int size)
{
	int			x;
	int			y;
	static int	turn = 0;
	char		**check;

	ft_init_coord(&x, &y);
	if (tab[i] == 0)
		return (grid);
	while (y < size)
	{
		if (is_possible(tab[i], y, x, grid))
		{
			grid = replace(tab[i], y, x, grid);
			if ((check = backtrack(tab, grid, i + 1, size)))
				return (check);
			grid = ft_delete(tab[i], y, x, grid);
		}
		whos_next(&y, &x, size);
	}
	if (i > 0)
		return (0);
	else if (tab[turn++] && (tab = rotate_tab(tab)))
		return (backtrack(tab, grid, 0, size));
	else
		return (end(turn, grid));
}

void			fillit(char ***tab)
{
	int			size_grid;
	char		**grid;

	size_grid = check_gridmin(tab);
	grid = get_grid(size_grid);
	while (!(grid = backtrack(tab, grid, 0, size_grid)))
	{
		size_grid++;
		grid = get_grid(size_grid);
	}
	ft_puttab(grid);
	ft_tabdel(grid);
}
