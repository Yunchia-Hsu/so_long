/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:12:03 by yhsu              #+#    #+#             */
/*   Updated: 2024/03/13 12:13:35 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_select(t_game *data, size_t y, size_t x)
{
	size_t	image_size;

	image_size = 32;
	if (data->grid[y][x] == '1')
		if (mlx_image_to_window(data->mlx, data->img->tree,
				x * PIXELS, y * PIXELS) < 0)
			error_message("failed to load image(tree) to window", data);
	if (data->grid[y][x] == 'C')
		if (mlx_image_to_window(data->mlx, data->img->eyeball,
				x * PIXELS, y * PIXELS) < 0)
			error_message("failed to load image(eyeball) to window", data);
	if (data->grid[y][x] == 'P')
		if (mlx_image_to_window(data->mlx, data->img->player,
				x * PIXELS, y * PIXELS) < 0)
			error_message("failed to load image(player) to window", data);
	if (data->grid[y][x] == 'E')
		if (mlx_image_to_window(data->mlx, data->img->gravestone,
				x * PIXELS, y * PIXELS) < 0)
			error_message("failed to load image(gravestone) to window", data);
}

void	render_map(t_game *data)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			image_select(data, y, x);
			x++;
		}
		y++;
	}
}

void	fill_background(t_game *data)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (mlx_image_to_window(data->mlx, data->img->floor,
					x * PIXELS, y * PIXELS) < 0)
				error_message("Failed to put image to window", data);
			x++;
		}
		y++;
	}
}
