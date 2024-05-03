/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:59:39 by yhsu              #+#    #+#             */
/*   Updated: 2024/03/13 12:14:28 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_grid(char **grid, size_t height)
{
	size_t	i;

	i = 0;
	while (i < height)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

int	check_path(t_game *temp, size_t y, size_t x)
{
	if (temp->grid[y][x] == '1')
		return (0);
	if (temp->grid[y][x] == 'C')
		temp->eyeball--;
	if (temp->grid[y][x] == 'E')
	{
		temp->exit_x = 1;
		return (0);
	}
	temp->grid[y][x] = '1';
	if (check_path(temp, y, x + 1))
		return (1);
	if (check_path(temp, y, x - 1))
		return (1);
	if (check_path(temp, y + 1, x))
		return (1);
	if (check_path(temp, y - 1, x))
		return (1);
	return (0);
}

int	flood_fill(t_game *game)
{
	t_game	temp;
	size_t	i;

	temp.width = game->width;
	temp.height = game->height;
	temp.eyeball = game->eyeball;
	temp.player_x = game->player_x;
	temp.player_y = game->player_y;
	temp.exit_x = 0;
	temp.grid = (char **)malloc(temp.height * sizeof(char *));
	if (!temp.grid)
		error_message("Memory allocation failed2", game);
	i = 0;
	while (i < temp.height)
	{
		temp.grid[i] = ft_strdup(game->grid[i]);
		if (!temp.grid[i])
			return (-1);
		i++;
	}
	check_path(&temp, temp.player_y, temp.player_x);
	if (!(temp.eyeball == 0 && temp.exit_x == 1))
		error_message("No valid path available", game);
	free_grid(temp.grid, temp.height);
	return (0);
}
