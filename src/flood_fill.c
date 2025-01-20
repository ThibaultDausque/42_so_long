/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 22:34:23 by thibault          #+#    #+#             */
/*   Updated: 2025/01/20 21:56:25 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>
#include <string.h>

void	fill(char **map, t_point size, t_point cur, char to_fill)
{
	if (cur.x < 0 || cur.y < 0 || cur.x >= size.x || cur.y >= size.y
		|| map[cur.y][cur.x] == to_fill || map[cur.y][cur.x] == '1')
		return ;
	map[cur.y][cur.x] = to_fill;
	fill(map, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(map, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(map, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(map, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill(char **map, t_point size, t_point begin)
{
	fill(map, size, begin, 'F');
}


char	**dup_map(char **map)
{
	char	**dup_map;
	int		count;
	int		x;
	int		y;

	if (!map)
		return (NULL);
	count = 0;
	while (map[count])
		count++;
	dup_map = (char **)malloc(sizeof(char *) * (count + 1));
	if (!dup_map)
		return (NULL);
	y = 0;
	while (map[y])
	{
		dup_map[y] = (char *)malloc(sizeof(char) * (strlen(map[y]) + 1));
		if (!dup_map[y])
		{
			while (y-- > 0)
				free(dup_map[y]);
			free(dup_map);
			return (NULL);
		}
		x = 0;
		while (map[y][x])
		{
			dup_map[y][x] = map[y][x];
			x++;
		}
		dup_map[y][x] = '\0';
		y++;
	}
	dup_map[y] = NULL;
	return (dup_map);
}

int	map_is_playable(char **map, t_point size, t_point begin)
{
	int		x;
	int		y;

	if (!map)
		return (0);
	flood_fill(map, size, begin);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != 'F' && map[y][x] == 'C')
				return (0);
			else if (map[y][x] != 'F' && map[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int main(void)
{
	char	**map;
	t_point	size = {7, 4};
	t_point	begin = {1, 1};
	int		is_playable;
	int		y;
		
	char *zone[] = {
		"11111111",
		"1P000001",
		"1000C011",
		"100001E1",
		"11111111",
		NULL
	};

	map = dup_map(zone);
	is_playable = map_is_playable(map, size, begin);
	printf("%d\n", is_playable);
	y = 0;
	while (map[y])
		printf("%s\n", map[y++]);
	return (0);
}