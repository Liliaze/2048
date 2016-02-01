/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ncurse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 09:41:37 by dboudy            #+#    #+#             */
/*   Updated: 2016/01/31 20:05:17 by atheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int main(void)
{	
	t_map	*map;
	int 	*grid; 
	int		score;
	int		first;

	grid = (int *)malloc(sizeof(int) * 17);
	score = 0;
	first = 0;
	initscr();
	init_curses();
	fill_map(map);
	transfert(map, grid);
	while(1)// Boucle infinie d'algo du jeu
	{
		main_print(map, grid, &score, &first); // affichage a chaque tour de la grille;
	}
	endwin();              // Restaure les paramètres par défaut du terminal
	return (0);
}
