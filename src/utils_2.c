/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:25:53 by tdausque          #+#    #+#             */
/*   Updated: 2025/01/12 13:27:26 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	loop_item_exit(t_game *game, int x, int y)
{
	int		img_width;
	int		img_height;

	if (!game)
		return ;
	img_width = game->img_width * y;
	img_height = game->img_height * x;
	if (game->map[x][y] == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->item_img, img_width + game->pos_x,
			img_height + game->pos_y);
}

void	loop_floor_wall(t_game *game, int x, int y)
{
	int		img_width;
	int		img_height;

	if (!game)
		return ;
	img_width = game->img_width * y;
	img_height = game->img_height * x;
	if (game->map[x][y] == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->wall_img, img_width + game->pos_x,
			img_height + game->pos_y);
	if (game->map[x][y] == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->floor_img, img_width + game->pos_x,
			img_height + game->pos_y);
}

void	destroy_images(t_game *game)
{
	if (!game)
		return ;
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->floor_img)
		mlx_destroy_image(game->mlx, game->floor_img);
	if (game->player_img)
		mlx_destroy_image(game->mlx, game->player_img);
	if (game->item_img)
		mlx_destroy_image(game->mlx, game->item_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx, game->exit_img);
	game->wall_img = NULL;
	game->floor_img = NULL;
	game->player_img = NULL;
	game->item_img = NULL;
	game->exit_img = NULL;
}
