/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:02:33 by floblanc          #+#    #+#             */
/*   Updated: 2018/12/10 12:39:47 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_sl(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	***end_tab(char ***tab, int i, char *file)
{
	int		fd;
	int		ret;
	char	buf[i * 5];

	fd = open(file, O_RDONLY);
	if (i % 5 != 4)
		quit_error(tab);
	while ((++i / 5) <= 26)
	{
		free(tab[i / 5]);
		tab[i / 5] = 0;
	}
	if (!(ret = read(fd, buf, i * 5)))
		quit_error(tab);
	buf[ret] = '\0';
	if (buf[ret - 1] != '\n' || (buf[ret - 2] != '.' && buf[ret - 2] != '#'))
		quit_error(tab);
	close(fd);
	return (tab);
}

char		***reader(char *file)
{
	char	***tab;
	char	*ln;
	int		i;
	int		fd;

	i = 0;
	if (!(tab = (char***)ft_memalloc(sizeof(char**) * 27)))
		quit_error(tab);
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &ln) && (i / 5) < 26)
	{
		if (((i % 5) == 4 && ln[0] != '\0')
				|| ((i % 5) != 4 && ft_sl(ln) != 4))
			quit_error(tab);
		if (i % 5 == 0 && (!(tab[i / 5] =
						(char**)ft_memalloc(sizeof(char*) * 5))))
			quit_error(tab);
		if (i % 5 != 4)
			(!(tab[i / 5][i % 5] = ft_strdup(ln))) ? quit_error2(tab, ln) : 0;
		free(ln);
		i++;
	}
	tab = end_tab(tab, i, file);
	close(fd);
	return (tab);
}
