# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atheveno <atheveno@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/09 17:23:00 by atheveno          #+#    #+#              #
#    Updated: 2016/01/31 19:54:34 by atheveno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

all:
	@gcc full_map.c ft_random.c transfert.c moves.c move_left.c move_right.c move_top.c move_bot.c rotate.c print_tab.c fill_map.c main_print.c init_curses.c main_test.c print_in_middle.c print_grid_and_title.c -lncurses
#	@gcc -Werror -Wextra -Wall main.c ../libft.a -I../includes/
	@echo "Compilation terminated.."

clean:
	@make -C ../ clean

fclean: clean
	@make -C ../ fclean

re: fclean all

