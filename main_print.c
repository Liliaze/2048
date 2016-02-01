/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ncurse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 09:41:37 by dboudy            #+#    #+#             */
/*   Updated: 2016/01/31 21:05:29 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	keyevent(int key, t_map *tab, int *score, int *grid)
{
	int *score_prec;

	score_prec = score;
	printf("%2d ", key);
	printf("%2d ", *score);
	if (key == 113 || key == 27)
		exit(1);
	if (key == 259)
		move_left(tab, score);
	else if (key == 258)
		move_right(tab, score);
	else if (key == 260)
		move_top(tab, score);
	else if (key == 261)
		move_bot(tab, score);
	if (full_map(tab) && (score_prec < score || tab->tmp > 0))
		ft_random(tab);
	transfert(tab, grid);
	tab->tmp = 0;
	return (key);
}

static int	print_loose(int *score)
{
	WINDOW	*final;

	erase();
	final = subwin(stdscr, LINES, COLS, 0, 0);
	wbkgd(final, COLOR_PAIR(1));
	box(final, ACS_VLINE, ACS_HLINE);
	wattron(final, COLOR_PAIR(3));
	print_in_middle(final, LINES / 2 - 3, ":(    :(    :(    :(    :(     :(", 0);
	print_in_middle(final, LINES / 2 - 2, ":(                             :(", 0);
	print_in_middle(final, LINES / 2 - 1, ":(            YOU LOOSE        :(", 0);
	print_in_middle(final, LINES / 2, "  Votre score est de : ", score);
	print_in_middle(final, LINES / 2 + 1, ":(                             :(", 0);
	print_in_middle(final, LINES / 2 + 2, ":(    :(    :(    :(     :(    :(", 0);
	wattroff(final, COLOR_PAIR(3));
	exit(1);
	return (1);
}

static int	print_victory(int *first, int *score)
{
	WINDOW	*final;

	*first = 2;
	erase();
	final = subwin(stdscr, LINES, COLS, 0, 0);
	wbkgd(final, COLOR_PAIR(1));
	box(final, ACS_VLINE, ACS_HLINE);
	wattron(final, COLOR_PAIR(5));
	print_in_middle(final, LINES / 2 - 2, "**********************************", 0);
	print_in_middle(final, LINES / 2 - 1, "*                                *", 0);
	print_in_middle(final, LINES / 2, "***** FELICITATION - YOU WIN *****", 0);
	print_in_middle(final, LINES / 2 + 1, "  Votre score est de : ", score);
	print_in_middle(final, LINES / 2 + 2, "*                                *", 0);
	print_in_middle(final, LINES / 2 + 3, "**********************************", 0);
	wattroff(final, COLOR_PAIR(5));
	return (1);
}

static int	win_or_loose(int *grid, int *score, int *first)
{
	int	i;
	int	full;
	int	move_possibility;

	i = -1;
	full = 0;
	move_possibility = 0;
	while (++i < 16)
	{
		if (grid[i] == WIN_VALUE && *first != 2)
			print_victory(first, score);
		if (grid[i] != 0)
		{
			if (i != 3 && i != 7 && i != 11 && i!= 15)
			{
				if (grid[i] == grid[i + 1])
					move_possibility = 1;
			}
			else if (i != 12 && i != 13 && i != 14 && i != 15)
				if (grid[i] == grid[i + 4])
					move_possibility = 1;
			full++;
		}
	}
	if (full == 16 && move_possibility == 0)
	{
		print_loose(score);
		*first = 2;
	}
	return (1);
}

int			main_print(t_map *tab, int *grid, int *score, int *first)
{
	WINDOW *title;
	WINDOW *game;
	int		key;

	key = 0;
	erase();
	title = subwin(stdscr, LINES / 3, COLS, 0, 0);
	game = subwin(stdscr, (LINES / 3) * 2, COLS, LINES /3, 0);
	wbkgd(game, COLOR_PAIR(1));
	box(title, ACS_VLINE, ACS_HLINE);
	wborder(game, '|', '|', '-', '-', '+', '+', '+', '+');
	print_all(title, game, grid, score);
	refresh();
	win_or_loose(grid, score, first);
	noecho();
	key = getch();
	keyevent(key, tab, score, grid);
	return (1);
}
