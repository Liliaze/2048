/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atheveno <atheveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 23:51:18 by atheveno          #+#    #+#             */
/*   Updated: 2016/01/31 20:59:29 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	move_gen(t_map *tab, int *sc)
{
	tab->changed = 1;
	while (tab->changed == 1 && !(tab->j = 0))
	{
		tab->changed = 0;
		while (tab->j <= 3 && !(tab->i = 0))
		{
			while (tab->i < 3)
			{
				if (tab->map[tab->j][tab->i] == 0 && \
						tab->map[tab->j][tab->i + 1] != 0)
				{
					tab->tmp = tab->changed = 1;
					tab->map[tab->j][tab->i] = tab->map[tab->j][tab->i + 1];
					tab->map[tab->j][tab->i + 1] = 0;
				}
				if (tab->map[tab->j][tab->i] == tab->map[tab->j][tab->i + 1])
				{
					*sc += tab->map[tab->j][tab->i] += tab->map[tab->j][tab->i];
					tab->map[tab->j][tab->i + 1] = 0;
				}
				tab->i++;
			}
			tab->j++;
		}
	}
}
