/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:40:40 by yhsu              #+#    #+#             */
/*   Updated: 2024/03/12 13:04:33 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_map_shape(char *map)
{
	int	len;
	int	row;
	int	i;

	len = 0;
	i = 0;
	row = 0;
	while (map[i] != '\n')
	{
		len++;
		i++;
	}
	while (map[i])
	{
		i++;
		if (map[i] == '\n')
			row++;
		if (map[i] == '\n' && (i - row) % len != 0)
		{
			error_message("Map is not rectangular", NULL);
		}
	}
}

void	check_wall(t_game *game)
{
	size_t	i;

	i = 0;
	while (game->grid[i])
	{
		if (game->grid[i][0] != '1')
			error_message("The map is not surrounded by walls", game);
		if (game->grid[i][game->width - 1] != '1')
			error_message("The map is not surrounded by walls", game);
		i++;
	}
	i = 0;
	while (game->grid[0][i] || game->grid[game->height - 1][i])
	{
		if (game->grid[0][i] != '1')
			error_message("The map is not surrounded by walls", game);
		if (game->grid[game->height - 1][i] != '1')
			error_message("The map is not surrounded by walls", game);
		i++;
	}
}
