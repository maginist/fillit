# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: floblanc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/26 10:46:03 by floblanc          #+#    #+#              #
#    Updated: 2018/12/10 13:16:47 by maginist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = reader.c\
	  is_valide.c\
	  get_next_line.c\
	  main.c\
	  get_grid.c\
	  push_up.c\
	  is_possible.c\
	  replace.c\
	  fillit.c\
	  free3char.c\
	  rotate_tab.c\
	  check_gridmin.c\
	  quit_error.c\
	  quit_error2.c\
	  reset_tab.c\
	  ft_delete.c

OBJS = $(SRC:.c=.o)

FLGS = -Wall -Wextra -Werror

INC = fillit.h

all : $(NAME)

$(NAME) : $(INC) $(SRC) $(OBJS)
		make -C libft/
		gcc $(FLGS) -c $(SRC) -I$(INC)
		gcc $(FLGS) -o $(NAME) $(OBJS) libft/libft.a

clean :
	rm -f $(OBJS)
	make clean -C libft

fclean : clean
	rm -f $(NAME)
	rm -f libft/libft.a

re : fclean all
