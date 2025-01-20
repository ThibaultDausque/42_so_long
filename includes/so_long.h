/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 14:00:53 by tdausque          #+#    #+#             */
/*   Updated: 2025/01/20 19:13:52 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include <fcntl.h>
# include <stdlib.h>

# define ER_FD "La map choisi n'existe pas."
# define ALL_ERR "Erreur d'allocation memoire."
# define SIZE_ERR "Erreur de dimensions."
# define WALL_ERR "La map n'est pas ferme."
# define EXIT_ERR "Il faut une sortie."
# define START_ERR "Il faut une position de depart."
# define ITEM_ERR "Il faut des items a collecter."
# define FILE_ERR "Erreur lors de l'execution du fichier (.ber)."

typedef struct  s_point
{
    int           x;
    int           y;
}	t_point;

typedef struct s_game
{
	int		pos_x;
	int		pos_y;
	void	*mlx;
	void	*mlx_win;
	char	**map;
	char	*filename;
	void	*wall_img;
	void	*item_img;
	void	*exit_img;
	void	*player_img;
	void	*floor_img;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	char	*player;
	char	*wall;
	char	*floor;
	char	*exit;
	char	*item;
	int		img_width;
	int		img_height;
}	t_game;

int		valid_map_and_size(t_game *game);
char	**get_map(t_game *game);
int		size_check(char **map);
int		enclosed_map(char **map);
int		map_item(char **map);
int		map_start(t_game *game, char **map);
int		map_exit(char **map);
int		map_elements(t_game *game);
void	create_window(t_game *game);
int		correct_file(char *filename);
int		ft_strcmp(char *s1, char *s2);
char	*find_dot(char *str, char c);
void	free_map(t_game *game);
int		close_window(t_game *game);
int		center_x(char **map);
int		center_y(char **map);
void	loop_item_exit(t_game *game, int x, int y);
void	put_item_exit(t_game *game, char **map);
void	put_floor_and_wall(t_game *game, char **map);
void	loop_floor_wall(t_game *game, int x, int y);
void	move_player(t_game *game, int dx, int dy);
int		key_handler(int keycode, t_game *game);
void	create_map(t_game *game);
void	destroy_images(t_game *game);
void	put_player(t_game *game, char **map);
void	render_map(t_game *game, int x, int y);
int		count_items(char **map);
int		enclosed_map(char **map);
void	flood_fill(char **map, t_point size, t_point begin);
void	fill(char **map, t_point size, t_point cur, char to_fill);
char	**dup_map(char **map);
#endif
