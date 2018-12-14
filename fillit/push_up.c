/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:18:45 by floblanc          #+#    #+#             */
/*   Updated: 2018/11/29 16:08:12 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	line_left(char **tetri)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = -1;
	tmp = ft_strnew(4);
	while (++j < 4)
		tmp[j] = tetri[j][0];
	while (i < 3)
	{
		j = 0;
		while (j < 4)
		{
			tetri[j][i] = tetri[j][i + 1];
			j++;
		}
		i++;
	}
	j = -1;
	while (++j < 4)
		tetri[j][i] = tmp[j];
	free(tmp);
}

char	***push_left(char ***tab)
{
	int	i;

	i = 0;
	while (tab[i / 5])
	{
		if (tab[i / 5][i % 5][0] != '.')
			i += 5 - (i % 5) - 1;
		else if (i % 5 == 3)
		{
			line_left(tab[i / 5]);
			i -= ((i % 5) + 1);
		}
		i++;
	}
	return (tab);
}

void	line_up(char **tetri)
{
	char	*tmp;
	int		i;

	tmp = ft_strdup(tetri[0]);
	i = 0;
	while (i < 3)
	{
		tetri[i] = ft_strcpy(tetri[i], tetri[i + 1]);
		i++;
	}
	tetri[i] = ft_strcpy(tetri[i], tmp);
	free(tmp);
}

char	***push_up(char ***tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i / 5])
	{
		j = 0;
		while (j < 4)
		{
			if (tab[i / 5][0][j] != '.')
			{
				i += 4;
				j = 3;
			}
			else if (i % 5 == 1)
			{
				line_up(tab[i / 5]);
				i -= 1;
				j = -1;
			}
			j++;
		}
		i++;
	}
	return (push_left(tab));
}
