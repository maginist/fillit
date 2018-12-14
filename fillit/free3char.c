/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free3char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:12:10 by maginist          #+#    #+#             */
/*   Updated: 2018/12/07 14:46:23 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free3char(char ****tab)
{
	int		i;
	int		j;
	int		y;
	char	***tmp;

	tmp = *tab;
	i = 0;
	if (!(tmp))
		return ;
	while (tmp[i])
	{
		j = 0;
		y = 0;
		while (j < 4 && tmp[i][j] && tmp[i][j][y])
		{
			free(tmp[i][j]);
			j++;
			y++;
		}
		free(tmp[i]);
		i++;
	}
	free(tmp);
}
