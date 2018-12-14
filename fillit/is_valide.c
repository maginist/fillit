/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valide.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:43:34 by floblanc          #+#    #+#             */
/*   Updated: 2018/12/10 11:03:28 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	if_forest(char ***tab, int i, int *j, int *link)
{
	if ((i % 5) > 0 && (tab[i / 5][(i % 5) - 1][*j] == '#' ||
				tab[i / 5][(i % 5) - 1][*j] == 'A' + (i / 5)))
		*link += 1;
	if ((i % 5) < 3 && (tab[i / 5][(i % 5) + 1][*j] == '#' ||
				tab[i / 5][(i % 5) + 1][*j] == 'A' + (i / 5)))
		*link += 1;
	if (*j > 0 && (tab[i / 5][i % 5][*j - 1] == '#' ||
				tab[i / 5][i % 5][*j - 1] == 'A' + (i / 5)))
		*link += 1;
	if (*j < 3 && (tab[i / 5][i % 5][*j + 1] == '#' ||
				tab[i / 5][i % 5][*j + 1] == 'A' + (i / 5)))
		*link += 1;
}

int		is_correct(char ***tab)
{
	int		i;
	int		j;
	int		link;

	i = 0;
	link = 0;
	while (tab[i / 5])
	{
		j = -1;
		while (++j < 4 && (i % 5) < 4)
			if (tab[i / 5][i % 5][j] == '#')
			{
				if_forest(tab, i, &j, &link);
				tab[i / 5][i % 5][j] = 'A' + (i / 5);
			}
		i++;
		if (i % 5 == 4)
		{
			if (link < 6)
				return (0);
			link = 0;
		}
	}
	return (1);
}

int		is_valide(char ***tab)
{
	int		i;
	int		j;
	int		diez;
	int		dot;

	i = 0;
	dot = 0;
	diez = 0;
	while (tab[i / 5])
	{
		j = -1;
		while (++j < 4 && (i % 5) < 4)
			if (tab[i / 5][i % 5][j] == '.')
				dot++;
			else if (tab[i / 5][i % 5][j] == '#')
				diez++;
		if (i % 5 == 3 && (diez != 4 || dot != 12))
			return (0);
		if (i % 5 == 3)
			dot = 0;
		if (i % 5 == 3)
			diez = 0;
		i++;
	}
	return (is_correct(tab));
}
