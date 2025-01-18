/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 07:46:08 by tdausque          #+#    #+#             */
/*   Updated: 2025/01/18 13:32:12 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// centrer les elemts de la map
int	center_x(char **map)
{
	int		x;
	int		count;

	count = 0;
	while (map[count])
		count++;
	x = (1920 - (count * 32)) / 2;
	return (x);
}

int	center_y(char **map)
{
	int		y;
	int		count_x;
	int		count_y;

	count_x = 0;
	while (map[count_x])
	{
		count_y = 0;
		while (map[count_x][count_y])
			count_y++;
		count_x++;
	}
	y = (1080 - (count_y * 32)) / 2;
	return (y);
}

// creer un strcmp pour l'occurence de ".ber"
int	ft_strcmp(char *s1, char *s2)
{
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] && s2[j] && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return (s1[i] - s2[j]);
}

void	free_map(t_game *game)
{
	int		i;

	if (!game || !game->map)
		return ;
	i = 0;
	while (game->map[i])
		free(game->map[i++]);
	free(game->map);
	game->map = NULL;
}

int	close_window(t_game *game)
{
	if (!game)
		return (0);
	destroy_images(game);
	free_map(game);
	if (game->mlx && game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	free(game->mlx);
	exit(0);
}
