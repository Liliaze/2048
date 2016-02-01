/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 13:30:54 by dboudy            #+#    #+#             */
/*   Updated: 2016/01/31 20:08:35 by atheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void		print_in_middle(WINDOW *win, int y, char *string, int *number)
{
	int	lenght;
	int	x;

	if (number == 0)
		lenght = strlen(string);
	else
		lenght = strlen(string) + 6;
	x = (COLS / 2) - (lenght / 2);
	if (number != 0)
		mvwprintw(win, y, x, "%s%d", string, *number);
	else
		mvwprintw(win, y, x, "%s", string);
}
