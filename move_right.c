/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atheveno <atheveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 17:04:49 by atheveno          #+#    #+#             */
/*   Updated: 2016/01/31 18:54:41 by atheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	move_right(t_map *tab, int *score)
{
	rotate(tab);
	rotate(tab);
	move_gen(tab, score);
	rotate(tab);
	rotate(tab);
}
