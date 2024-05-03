/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:16:11 by yhsu              #+#    #+#             */
/*   Updated: 2024/03/13 13:22:33 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delay(int milliseconds)
{
	long	pause;
	clock_t	now;
	clock_t	then;

	pause = milliseconds * (CLOCKS_PER_SEC / 1000);
	then = clock();
	now = clock();
	while ((now - then) < (clock_t)pause)
	{
		now = clock();
	}
	return ;
}

void	check_status(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->img->enemy[0]->count)
	{
		if (game->player_x * PIXELS == (size_t)game->img->enemy[0]
			->instances[i].x && game->player_y * PIXELS
			== (size_t)game->img->enemy[0]->instances[i].y)
		{
			mlx_close_window(game->mlx);
			ft_printf ("Oh no! You lost the game! 😱\n");
		}
		i++;
	}
}

void	check_game_status(t_game *game)
{
	print_moves(game);
	if (game->collected == game->eyeball)
	{
		game->grid[game->exit_y][game->exit_x] = '0';
		if (game->player_y == game->exit_y && game->player_x == game->exit_x)
		{
			sleep(1);
			mlx_close_window(game->mlx);
			ft_printf("🥰 Congratulations 🥰\n");
			ft_printf("You may Rest in Peace now!😎\n");
		}
	}
}

size_t	row_count(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}
