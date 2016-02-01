/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ncurse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 09:41:37 by dboudy            #+#    #+#             */
/*   Updated: 2016/01/31 18:41:06 by atheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void init_curses(void)
{
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLUE);
	init_pair(2, COLOR_BLUE, COLOR_WHITE);
	init_pair(3, COLOR_RED, COLOR_YELLOW);
	init_pair(4, COLOR_GREEN, COLOR_WHITE);
	init_pair(5, COLOR_BLUE, COLOR_GREEN);
	curs_set(0);
	noecho();
	keypad(stdscr,TRUE);
}
