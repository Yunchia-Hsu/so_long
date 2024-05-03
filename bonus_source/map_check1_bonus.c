/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check1_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:36:37 by yhsu              #+#    #+#             */
/*   Updated: 2024/03/13 13:29:34 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_empty_line(char *map)
{
	int	i;

	i = 0;
	if (!map[0] || map[0] == '\n')
		error_message("Map is Empty!", NULL);
	while (map[i])
	{
		if ((map[i] == '\n' && map[i + 1] == '\n'))
			error_message("There is an Empty line!", NULL);
		i++;
	}
	if (map[i - 1] == '\n')
		error_message("There is an Empty line after the last line", NULL);
}

void	check_invalid_content(int i)
{
	if (!ft_strchr("PEC01X\n", i))
		error_message("invalid character", NULL);
}

void	check_map_content(char *map)
{
	int	exit;
	int	eyeball;
	int	player;
	int	i;

	exit = 0;
	eyeball = 0;
	player = 0;
	i = 0;
	while (map[i])
	{
		if (map[i] == 'E')
			exit++;
		else if (map[i] == 'C')
			eyeball++;
		else if (map[i] == 'P')
			player++;
		else
			check_invalid_content(map[i]);
		i++;
	}
	if (exit != 1 || eyeball < 1 || player != 1)
		error_message("Map content is not valid", NULL);
}

void	check_map_size(char **grid)
{
	if (row_count(grid) > 22 || ft_strlen(grid[0]) > 40)
	{
		delete_map(grid, row_count(grid));
		error_message("Unvalid map size", NULL);
	}
}
