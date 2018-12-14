/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_error2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 10:18:57 by maginist          #+#    #+#             */
/*   Updated: 2018/12/10 10:20:11 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	quit_error2(char ***tab, char *line)
{
	if (tab)
		free3char(&tab);
	if (line)
		free(line);
	write(1, "error\n", 6);
	exit(0);
}
