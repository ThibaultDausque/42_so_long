/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:05:53 by tdausque          #+#    #+#             */
/*   Updated: 2025/01/18 12:23:53 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// verifier l'extension .ber
int	correct_file(char *filename)
{
	int		i;

	i = 0;
	while (filename[i])
	{
		if (filename[i] == '.')
		{
			if (i == 0)
				return (0);
			if (ft_strcmp(ft_strchr(filename, '.'), ".ber") == 0)
				return (1);
		}
		i++;
	}
	return (0);
}

// minimum un collectible
int	map_item(char **map)
{
	int		i;
	int		j;
	int		item;

	if (!map)
		return (0);
	i = 0;
	item = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				item++;
			j++;
		}
		i++;
	}
	if (item > 0)
		return (1);
	return (0);
}

// au moins une position de depart
int	map_start(t_game *game, char **map)
{
	int		i;
	int		j;
	int		start;

	i = 0;
	start = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				start++;
			}
			j++;
		}
		i++;
	}
	if (start == 1)
		return (1);
	return (0);
}

// au moins une position de sortie
int	map_exit(char **map)
{
	int		i;
	int		j;
	int		exit;

	if (!map)
		return (0);
	i = 0;
	exit = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	if (exit == 1)
		return (1);
	return (0);
}

int	map_elements(t_game *game)
{
	int		result;

	result = 1;
	if (!map_item(game->map))
	{
		ft_printf("%s\n", ITEM_ERR);
		result = 0;
	}
	if (!map_exit(game->map))
	{
		ft_printf("%s\n", EXIT_ERR);
		result = 0;
	}
	if (!map_start(game, game->map))
	{
		ft_printf("%s\n", START_ERR);
		result = 0;
	}
	if (!enclosed_map(game->map))
	{
		ft_printf("%s\n", WALL_ERR);
		result = 0;
	}
	else if (!correct_file(game->filename))
	{
		ft_printf("%s\n", FILE_ERR);
		result = 0;
	}
	return (result);
}
