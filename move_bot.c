/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atheveno <atheveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 17:05:21 by atheveno          #+#    #+#             */
/*   Updated: 2016/01/31 18:54:15 by atheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	move_bot(t_map *tab, int *score)
{
	rotate(tab);
	move_gen(tab, score);
	rotate(tab);
	rotate(tab);
	rotate(tab);
}
