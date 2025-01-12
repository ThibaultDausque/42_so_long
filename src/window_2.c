/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:02:20 by tdausque          #+#    #+#             */
/*   Updated: 2025/01/12 13:41:03 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	render_map(t_game *game, int x, int y)
{
	int		img_width;
	int		img_height;
	
	if (!game || !game->map)
		return ;
	game->pos_x = center_x(game->map);
	game->pos_y = center_y(game->map);
	y = 0;
	while (game->map[y])
	{
		x = 0;
		img_height = game->img_height * y;
		while (game->map[y][x])
		{
			img_width = game->img_width * x;
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->wall_img, img_width + game->pos_x,
					img_height + game->pos_y);
			if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->floor_img, img_width + game->pos_x,
					img_height + game->pos_y);
			if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->item_img, img_width + game->pos_x,
					img_height + game->pos_y);
			if (game->map[y][x] == 'E' && count_items(game->map) == 0)
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->exit_img, img_width + game->pos_x,
					img_height + game->pos_y);
			if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->player_img, img_width + game->pos_x,
					img_height + game->pos_y);
			x++;
		}
		y++;
	}
}
