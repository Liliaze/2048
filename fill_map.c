/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atheveno <atheveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 17:03:05 by atheveno          #+#    #+#             */
/*   Updated: 2016/01/31 19:18:00 by atheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	fill_map(t_map *tab)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i <= 3)
	{
		j = 0;
		while (j <= 3)
		{
			tab->map[j][i] = 0;
			j++;
		}
		i++;
	}
	ft_random(tab);
	ft_random(tab);
}
