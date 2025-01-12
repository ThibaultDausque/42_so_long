/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:06:06 by tdausque          #+#    #+#             */
/*   Updated: 2025/01/10 09:47:39 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

// afficher le joueur
void	put_player(t_game *game, char **map)
{
	int		x;
	int		y;
	int		img_width;
	int		img_height;

	if (!game || !map)
		return ;
	game->pos_x = center_x(map);
	game->pos_y = center_y(map);
	x = 0;
	while (map[x])
	{
		y = 0;
		img_width = game->img_width * x;
		while (map[x][y])
		{
			img_height = game->img_height * y;
			if (map[x][y] == 'P')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->player_img, img_width + game->pos_x,
					img_height + game->pos_y);
			y++;
		}
		x++;
	}
}

//afficher les items, la sortie et le player
void	put_item_exit(t_game *game, char **map)
{
	int		x;
	int		y;

	if (!map || !game)
		return ;
	game->pos_x = center_x(map);
	game->pos_y = center_y(map);
	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			loop_item_exit(game, x, y);
			y++;
		}
		x++;
	}
}

// afficher les sprites (mur & sol)
void	put_floor_and_wall(t_game *game, char **map)
{
	int		x;
	int		y;

	if (!map || !map)
		return ;
	game->pos_x = center_x(map);
	game->pos_y = center_y(map);
	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			loop_floor_wall(game, x, y);
			y++;
		}
		x++;
	}
}

// recuperer les sprites
void	create_map(t_game *game)
{
	if (!game)
		return ;
	// proteger les img chmod etc... int valid_xpm()
	game->wall = "./sprites/walls/wall.xpm";
	game->floor = "./sprites/walls/black.xpm";
	game->exit = "./sprites/portal/portal.xpm";
	game->item = "./sprites/pacdots/pacdot_powerup.xpm";
	game->player = "./sprites/megaman/megaman.xpm";
	game->wall_img = mlx_xpm_file_to_image(game->mlx, game->wall,
			&game->img_width, &game->img_height);
	game->floor_img = mlx_xpm_file_to_image(game->mlx, game->floor,
			&game->img_width, &game->img_height);
	game->item_img = mlx_xpm_file_to_image(game->mlx, game->item,
			&game->img_width, &game->img_height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, game->exit,
			&game->img_width, &game->img_height);
	game->player_img = mlx_xpm_file_to_image(game->mlx, game->player,
			&game->img_width, &game->img_height);
	put_floor_and_wall(game, game->map);
	put_item_exit(game, game->map);
	put_player(game, game->map);
}

// Creation de la fenetre de jeu
void	create_window(t_game *game)
{
	if (!game)
		return ;
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, 1920, 1080, "so_long");
	create_map(game);
	mlx_hook(game->mlx_win, 17, 0, close_window, game);
	mlx_hook(game->mlx_win, 2, 1L << 0, key_handler, game);
	mlx_loop(game->mlx);
}
