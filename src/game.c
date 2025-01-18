/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:45:05 by tdausque          #+#    #+#             */
/*   Updated: 2025/01/18 13:44:15 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_player(t_game *game, int dx, int dy)
{
	int		x;
	int		y;

	if (!game)
		return ;
	x = game->player_x + dx;
	y = game->player_y + dy;
	if (game->map[y][x] == '1')
		return ;
	if (game->map[y][x] == 'C')
		game->map[y][x] = '0';
	if (game->map[y][x] == 'E')
	{
		if (count_items(game->map) == 0)
			close_window(game);
		else
			return ;
	}
	game->map[game->player_y][game->player_x] = '0';
	game->map[y][x] = 'P';
	game->player_x = x;
	game->player_y = y;
	mlx_clear_window(game->mlx, game->mlx_win);
	render_map(game, x, y);
}

int	key_handler(int keycode, t_game *game)
{
	if (keycode == 119)
		move_player(game, 0, -1);
	else if (keycode == 115)
		move_player(game, 0, 1);
	else if (keycode == 100)
		move_player(game, 1, 0);
	else if (keycode == 97)
		move_player(game, -1, 0);
	else if (keycode == 65307)
		close_window(game);
	return (0);
}
