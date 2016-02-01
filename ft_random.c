/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atheveno <atheveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 19:01:11 by atheveno          #+#    #+#             */
/*   Updated: 2016/01/31 20:56:48 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_random(t_map *tab)
{
	int i;
	int j;
	int k;

	i = rand() % 4;
	j = rand() % 4;
	srand(time(NULL));
	while (tab->map[j][i] != 0)
	{
		i = rand() % 4;
		j = rand() % 4;
	}
	k = rand() % 4;
	if (k < 3)
		tab->map[j][i] = 2;
	else if (k == 3)
		tab->map[j][i] = 4;
}
