/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:58:24 by tdausque          #+#    #+#             */
/*   Updated: 2025/01/09 18:16:35 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

// valide l'existence de la map et renvoi sa taille.
int	valid_map_and_size(t_game *game)
{
	int		fd;
	char	*buff;
	int		count;

	if (!game)
		return (0);
	count = 0;
	fd = open(game->filename, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		ft_printf("%s\n", ER_FD);
		return (0);
	}
	buff = get_next_line(fd);
	while (buff)
	{
		free(buff);
		buff = get_next_line(fd);
		count++;
	}
	close(fd);
	if (count == 0)
		return (0);
	return (count);
}

// decouper chaque ligne de la map
// dans un tableau (char **)
char	**get_map(t_game *game)
{
	int		map_size;
	int		i;
	int		fd;

	if (!game)
		return (NULL);
	i = 0;
	fd = open(game->filename, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		ft_printf("%s\n", ER_FD);
		return (NULL);
	}
	map_size = valid_map_and_size(game);
	game->map = (char **)malloc(sizeof(char *) * (map_size + 1));
	if (!game->map)
	{
		ft_printf("%s", ALL_ERR);
		return (NULL);
	}
	while (map_size > 0)
	{
		game->map[i++] = get_next_line(fd);
		map_size--;
	}
	game->map[i] = 0;
	close(fd);
	return (game->map);
}

// Check si la map est rectangulaire
int	size_check(char **map)
{
	int		i;
	int		j;
	int		k;
	int		l;

	if (!map)
		return (0);
	i = 0;
	j = i + 1;
	while (map[j])
	{
		k = 0;
		l = 0;
		while (map[i][k] != '\n')
			k++;
		while (map[j][l] != '\n' && map[j][l] != '\0')
			l++;
		if (k != l)
		{
			ft_printf("%s", SIZE_ERR);
			return (0);
		}
		i++;
		j++;
	}
	return (1);
}

// Analyser si la map est bien entoure de 1
int	enclosed_map(char **map)
{
	int		i;
	int		j;
	
	if (!map)
		return (0);
	j = 0;
	while (map[0][j] != '\n')
	{
		if (map[0][j] != '1')
			return (0);
		j++;
	}
	i = 1;
	while (map[i])
	{
		if (map[i][0] != '1')
			return (0);
		else if (map[i][j - 1] != '1')
			return (0);
		i++;
	}
	j = 0;
	while (map[i][j])
	{
		if (map[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}
