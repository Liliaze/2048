/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 12:32:32 by dboudy            #+#    #+#             */
/*   Updated: 2016/01/31 21:06:58 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <ncurses.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# define DEBUG write(1, "T\n", 2);

enum			e_const
{
	WIN_VALUE = 32
};

typedef struct	s_map
{
	int			map[4][4];
	int			i;
	int			j;
	int			changed;
	int			s;
	int			tmp;
}				t_map;

int				rotate(t_map *tab);
int				main_print(t_map *tab, int *grid, int *score, int *first);
int				print_all(WINDOW *title, WINDOW *game, int *grid, int *score);
int				full_map(t_map *tab);
void			print_tab(t_map *tab);
void			init_curses(void);
void			fill_map(t_map *tab);
void			move_gen(t_map *tab, int *sc);
void			move_right(t_map *tab, int *score);
void			move_left(t_map *tab, int *score);
void			move_top(t_map *tab, int *score);
void			move_bot(t_map *tab, int *score);
void			fill_map(t_map *tab);
void			print_in_middle(WINDOW *win, int y, char *string, int *number);
void			transfert(t_map *tab, int *grid);
void			ft_random(t_map *tab);
#endif
