/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:23:20 by yhsu              #+#    #+#             */
/*   Updated: 2024/03/12 19:03:33 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4 || ft_strncmp(file + len - 4, ".ber", 4) != 0)
		error_message("please provide a .ber file", NULL);
}

char	*read_map(char *map)
{
	char	*line;
	char	*all_lines;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		error_message("Open function failed", NULL);
	all_lines = ft_calloc(1, 1);
	if (!all_lines)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (line)
		{
			all_lines = ft_strjoin(all_lines, line);
			free(line);
		}
		else
			break ;
	}
	close(fd);
	return (all_lines);
}

int	count_eyeball(t_game *game)
{
	size_t	x;
	size_t	y;
	size_t	c;

	c = 0;
	x = 0;
	while (x < game->height)
	{
		y = 0;
		while (y < game->width)
		{
			if (game->grid[x][y] == 'C')
			{
				c++;
			}
			y++;
		}
		x++;
	}
	return (c);
}

size_t	get_exit_pos(t_game *game, char c)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->grid[y][x] == 'E')
			{
				if (c == 'x')
					return (x);
				else
					return (y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

size_t	get_player_pos(t_game	*game, char c)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->grid[y][x] == 'P')
			{
				if (c == 'x')
					return (x);
				else
					return (y);
			}
			x++;
		}
		y++;
	}
	return (0);
}
