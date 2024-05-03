/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_direction_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:42:24 by yhsu              #+#    #+#             */
/*   Updated: 2024/03/12 18:40:18 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	remove_eyeball(t_game *game, int y, int x)
{
	size_t	i;
	int		k;

	x = x * 64 ;
	y = y * 64 ;
	i = 0;
	k = 0;
	while (i < game->img->eyeball->count)
	{
		if (game->img->eyeball->instances[i].x == x
			&& game->img->eyeball->instances[i].y == y)
		{
			game->img->eyeball->instances[i].enabled = false;
		}
		i++;
		k++;
	}
}

t_game	*move_up(t_game *game)
{
	if (game->grid[game->player_y - 1][game->player_x] != '1'
		&& game->grid[game->player_y - 1][game->player_x] != 'E')
	{
		if (game->grid[game->player_y - 1][game->player_x] == 'C')
		{
			remove_eyeball(game, game->player_y - 1, game->player_x);
			print_eyeball(game);
			game->grid[game->player_y - 1][game->player_x] = '0';
			game->collected = game->collected + 1;
		}
		game->player_y -= 1;
		game->img->player->instances[0].y -= 1 * PIXELS;
		game->steps += 1;
	}
	check_game_status(game);
	return (game);
}

t_game	*move_down(t_game *game)
{
	if (game->grid[game->player_y + 1][game->player_x] != '1'
		&& game->grid[game->player_y + 1][game->player_x] != 'E')
	{
		if (game->grid[game->player_y + 1][game->player_x] == 'C')
		{
			remove_eyeball(game, game->player_y + 1, game->player_x);
			print_eyeball(game);
			game->grid[game->player_y + 1][game->player_x] = '0';
			game->collected += 1;
		}
		game->player_y += 1;
		game->img->player->instances[0].y += 1 * PIXELS;
		game->steps += 1;
	}
	check_game_status(game);
	return (game);
}

t_game	*move_left(t_game *game)
{
	if (game->grid[game->player_y][game->player_x - 1] != '1'
		&& game->grid[game->player_y][game->player_x - 1] != 'E')
	{
		if (game->grid[game->player_y][game->player_x - 1] == 'C')
		{
			print_eyeball(game);
			remove_eyeball(game, game->player_y, game->player_x - 1);
			game->grid[game->player_y][game->player_x - 1] = '0';
			game->collected += 1;
		}
		game->player_x -= 1;
		game->img->player->instances[0].x -= 1 * PIXELS;
		game->steps += 1;
	}
	check_game_status(game);
	return (game);
}

t_game	*move_right(t_game *game)
{
	if (game->grid[game->player_y][game->player_x + 1] != '1'
		&& game->grid[game->player_y][game->player_x + 1] != 'E')
	{
		if (game->grid[game->player_y][game->player_x + 1] == 'C')
		{
			remove_eyeball(game, game->player_y, game->player_x + 1);
			print_eyeball(game);
			game->collected += 1;
			game->grid[game->player_y][game->player_x + 1] = '0';
		}
		game->player_x += 1;
		game->img->player->instances[0].x += 1 * PIXELS;
		game->steps += 1;
	}
	check_game_status(game);
	return (game);
}
