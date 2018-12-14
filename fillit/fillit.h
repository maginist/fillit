/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:31:01 by floblanc          #+#    #+#             */
/*   Updated: 2018/12/10 10:20:50 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 50
# include <unistd.h>
# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_coord
{
	int				x;
	int				y;
	char			**check;
}					t_coord;

int					get_next_line(const int fd, char **line);
char				***reader(char *file);
int					is_valide(char ***tab);
char				**get_grid(int size);
void				fillit(char ***tab);
int					size_cube(char **grid);
char				***push_up(char ***tab);
int					is_possible(char **tab, int y, int x, char **grid);
char				**replace(char **tab, int y, int x, char **grid);
char				***rotate_tab(char ***tab);
int					check_gridmin(char ***tab);
char				***reset_tab(char ***tab, char ***tmp, int i);
char				**ft_delete(char **tab, int y, int x, char **grid);
void				free3char(char ****tab);
void				delete_grid(char **grid);
void				quit_error(char ***tab);
void				quit_error2(char ***tab, char *line);

#endif
