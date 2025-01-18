/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:52:01 by tdausque          #+#    #+#             */
/*   Updated: 2025/01/16 15:35:04 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int		count_items(char **map)
{
	int		x;
	int		y;
	int		count_item;

	y = 0;
	count_item = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				count_item++;
			x++;
		}
		y++;
	}
	return (count_item);
}