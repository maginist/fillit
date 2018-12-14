/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_gridmin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:13:15 by maginist          #+#    #+#             */
/*   Updated: 2018/12/03 15:14:45 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_gridmin(char ***tab)
{
	int	i;
	int	res;

	res = 2;
	i = 0;
	while (tab[i])
		i++;
	while (res * res < i * 4)
		res++;
	return (res);
}
