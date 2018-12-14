/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 11:36:31 by floblanc          #+#    #+#             */
/*   Updated: 2018/12/05 12:17:34 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	***rotate_tab(char ***tab)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	j = 0;
	while (tab[i])
		i++;
	while (j < i - 1)
	{
		tmp = tab[j];
		tab[j] = tab[j + 1];
		tab[j + 1] = tmp;
		j++;
	}
	return (tab);
}
