/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atheveno <atheveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 17:03:36 by atheveno          #+#    #+#             */
/*   Updated: 2016/01/31 17:09:58 by atheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	print_tab(t_map *tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j <= 3)
	{
		i = 0;
		while (i <= 3)
		{
			printf("%2d ", tab->map[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}
}
