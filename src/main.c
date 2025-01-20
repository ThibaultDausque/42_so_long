/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 19:21:22 by tdausque          #+#    #+#             */
/*   Updated: 2025/01/19 23:21:12 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_game	*game;
	int		elements;
	char	**map;
	int		i;

	(void) argc;
	if (argc != 2)
		return (0);
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
	{
		ft_printf("%s", ALL_ERR);
		return (0);
	}
	game->filename = argv[1];
	game->map = get_map(game);
	map = dup_map(game->map);
	i = 0;
	while (map[i])
		printf("%s\n", map[i++]);
	// elements = map_elements(game);
	// if (!elements)
	// 	return (0);
	// create_window(game);
	return (0);
}
