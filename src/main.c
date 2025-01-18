/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 19:21:22 by tdausque          #+#    #+#             */
/*   Updated: 2025/01/18 12:30:35 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include <so_long.h>

int	main(int argc, char **argv)
{
	t_game	*game;
	int		elements;

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
	elements = map_elements(game);
	if (!elements)
		return (0);
	create_window(game);
	return (0);
}
