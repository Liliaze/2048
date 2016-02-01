/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 13:30:54 by dboudy            #+#    #+#             */
/*   Updated: 2016/01/31 22:40:37 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void		draw_title(WINDOW *title, int *score)
{
	if (LINES < 27 || COLS < 35)
	{
		wbkgd(title, COLOR_PAIR(2));
		erase();
		print_in_middle(title, 2, "Please enlarge\nyour terminal\n", 0);
	}
	else
	{
		wbkgd(title, COLOR_PAIR(2));
		print_in_middle(title, 1, "     :::::::::	  ::::::::       :::       ::::::::  ", 0);
		print_in_middle(title, 2, "    :+:     :+:   :+:    :+:     ::+::     :+:    :+: ", 0);
		print_in_middle(title, 3, "   +:+   +:+    +:+     +:+   +:+  +:+    :+:    :+:  ", 0);
		print_in_middle(title, 4, "       +#+     +#+     +:+   +#+   +:+    +#+:+:+     ", 0);
		print_in_middle(title, 5, "     +#+	      +#+    +#+  +#+#+#+#+#+ +#+     +#+    ", 0);
		print_in_middle(title, 6, "   #+#	     +#+    +#+	       #+#   +#+     +#+     ", 0);
		print_in_middle(title, 7, " ##########    ######          ###     ########'s     ", 0);
		print_in_middle(title, 8, "G	  A		M	  E", 0);
		print_in_middle(title, 9, "by atheveno & dbourdy", 0);
		print_in_middle(title, 10, "Welcome and enjoy yourself !", 0);
		wattron(title, COLOR_PAIR(2));
		print_in_middle(title, 12, "- press q to quit !", 0);
		print_in_middle(title, 13, "- press enter to new_game !", 0);
		wattroff(title, COLOR_PAIR(2));
		wattron(title, COLOR_PAIR(3));
		print_in_middle(title, LINES - (LINES / 3 * 2) - 4, "score = ", score);
		wattroff(title, COLOR_PAIR(3));
	}
}

static int		print_grid(int i, WINDOW *game, int *grid)
{
	WINDOW	*boite[16];
	int		size_x;
	int		size_y;
	int		y;
	int		x;

	size_x = COLS / 5;
	size_y = (LINES / 4) / 2;
	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			boite[++i] = subwin(game, size_y, size_x, ((LINES / 3) * 2) - 2 *
					size_y + size_y * y, (size_x / 2) + size_x * x);
			wbkgd(boite[i], COLOR_PAIR(4));
			wborder(boite[i], '|', '|', '=', '=', '@', '@', '@', '@');
			wattron(boite[i], COLOR_PAIR(2));
			mvwprintw(boite[i], size_y / 2, size_x / 2, "%d", grid[i]);
			wattroff(boite[i], COLOR_PAIR(2));
		}
	}
	return (1);
}

int				print_all(WINDOW *title, WINDOW *game, int *grid, int *score)
{
	int i;

	i = -1;
	draw_title(title, score);
	print_grid(i, game, grid);
	return (1);
}
