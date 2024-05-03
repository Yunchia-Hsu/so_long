/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:12:08 by yhsu              #+#    #+#             */
/*   Updated: 2024/03/13 13:28:47 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_patrol(void *temp)
{
	t_game	*game;
	size_t	instances_e;

	game = (t_game *)temp;
	instances_e = 0;
	game->enemy_frames = 0;
	game->time = mlx_get_time();
	check_status(game);
	while (instances_e < game->img->enemy[0]->count)
	{
		if ((game->img->enemy[0])->count % 3 == 0)
		{
			print_enemy_3(game, instances_e);
		}
		else
			print_enemy (game, instances_e);
		instances_e++;
	}
}

void	print_enemy(t_game *game, size_t count)
{
	double		time_start;
	static int	i = 0;

	time_start = mlx_get_time();
	if (game->time >= 0)
	{
		game->img->enemy[i % 3]->instances[count].enabled = true;
		delay(60);
		game->img->enemy[(i + 1) % 3]->instances[count].enabled = false;
		game->img->enemy[(i + 2) % 3]->instances[count].enabled = false;
		i = (i + 1) % 3;
		game->time = mlx_get_time();
	}
	return ;
}

void	print_enemy_3(t_game *game, size_t count)
{
	double		time_start;
	static int	i = 0;

	time_start = mlx_get_time();
	if (game->time >= 0)
	{
		game->img->enemy[i % 3]->instances[count].enabled = true;
		delay(50);
		game->img->enemy[(i + 1) % 3]->instances[count].enabled = false;
		game->img->enemy[(i + 2) % 3]->instances[count].enabled = false;
		i = (i + 1) % 4;
		game->time = mlx_get_time();
	}
	return ;
}

void	enemy_to_window(t_game *data, size_t x, size_t y)
{
	if (mlx_image_to_window(data->mlx, data->img->enemy[0],
			x * PIXELS, y * PIXELS) < 0)
		error_message("failed to load image(enemy) to window", data);
	else
		data->img->enemy[0]->instances->enabled = false;
	if (mlx_image_to_window(data->mlx, data->img->enemy[1],
			x * PIXELS, y * PIXELS) < 0)
		error_message("failed to load image(enemy) to window", data);
	else
		data->img->enemy[1]->instances->enabled = false;
	if (mlx_image_to_window(data->mlx, data->img->enemy[2],
			x * PIXELS, y * PIXELS) < 0)
		error_message("failed to load image(enemy) to window", data);
	else
		data->img->enemy[2]->instances->enabled = false;
}

void	put_enemies(t_game *data)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->grid[y][x] == 'X')
			{
				enemy_to_window(data, x, y);
			}
			x++;
		}
		y++;
	}
}
