/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:52:13 by maginist          #+#    #+#             */
/*   Updated: 2018/12/05 12:18:00 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		fd_n_finish(char **str, char **line)
{
	int			ret;
	char		*tmp;

	ret = (int)ft_strlen(*str);
	if ((tmp = ft_strchr(*str, '\n')))
		*tmp = '\0';
	if ((int)ft_strlen(*str) < ret)
	{
		*line = ft_strdup(*str);
		if ((int)ft_strlen(*line) < ret - 1)
			*str = ft_strcpy(*str, *str + (int)ft_strlen(*line) + 1);
		else
			ft_strdel(str);
		return (1);
	}
	return (0);
}

int		start_fd(int fd, char **str, char **line)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	char		*tmp;

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if ((tmp = ft_strchr(buf, '\n')))
			*tmp = '\0';
		tmp = ft_strjoin(*str, buf);
		ft_strdel(str);
		*str = ft_strdup(tmp);
		free(tmp);
		if ((int)ft_strlen(buf) < ret)
		{
			*line = ft_strdup(*str);
			free(*str);
			if ((int)ft_strlen(buf) < ret - 1)
				*str = ft_strdup(buf + (int)ft_strlen(buf) + 1);
			else
				*str = NULL;
			return (1);
		}
	}
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str;
	int			ret;

	if (fd == -1 || BUFF_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (-1);
	if (str)
		if (fd_n_finish(&str, line))
			return (1);
	if (!(str))
		if (!(str = ft_strnew(0)))
			return (-1);
	if ((ret = start_fd(fd, &str, line)))
		return (1);
	if (ret == 0 && ft_strlen(str) > 0)
	{
		*line = ft_strdup(str);
		ft_strdel(&str);
		return (1);
	}
	if (ret == 0)
		ft_strdel(&str);
	return (ret);
}
