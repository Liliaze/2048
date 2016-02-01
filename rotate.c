/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atheveno <atheveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 17:01:59 by atheveno          #+#    #+#             */
/*   Updated: 2016/01/31 17:09:13 by atheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	rotate(t_map *tab)
{
	size_t	i;
	size_t	j;
	size_t	temp;

	j = 0;
	while (j < 2)
	{
		i = j;
		while (i < 3 - j)
		{
			temp = tab->map[i][j];
			tab->map[i][j] = tab->map[3 - j][i];
			tab->map[3 - j][i] = tab->map[3 - i][3 - j];
			tab->map[3 - i][3 - j] = tab->map[j][3 - i];
			tab->map[j][3 - i] = temp;
			i++;
		}
		j++;
	}
	return (0);
}
