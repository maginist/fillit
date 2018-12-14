/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:15:25 by maginist          #+#    #+#             */
/*   Updated: 2018/12/10 11:41:35 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	char	***tab;

	if (ac != 2)
	{
		write(1, "usage : ./fillit file\n", 22);
		return (0);
	}
	tab = reader(av[1]);
	if (!(tab) || !(is_valide(tab)))
		quit_error(tab);
	tab = push_up(tab);
	fillit(tab);
	free3char(&tab);
	return (0);
}
