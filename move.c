/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:00:40 by yhsu              #+#    #+#             */
/*   Updated: 2024/03/12 12:08:41 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_other_player_textures(t_game *game)
{
	game->player_up = mlx_load_png("./sprites/horseman_back.png");
	if (!game->player_up)
		error_message("Problem with loading png(b)", game);
	game->player_down = mlx_load_png("./sprites/horseman.png");
	if (!game->player_down)
		error_message("Problem with loading png(f)", game);
	game->player_left = mlx_load_png("./sprites/horseman_left1.png");
	if (!game->player_left)
		error_message("Problem with loading png(l)", game);
	game->player_right = mlx_load_png("./sprites/horseman_right1.png");
	if (!game->player_right)
		error_message("Problem with loading png(r)", game);
}

void	move_select(t_game *game, char line, char direction)
{
	if (line == 'y')
	{
		if (direction == 'u')
			move_up(game);
		else
			move_down(game);
	}
	if (line == 'x')
	{
		if (direction == 'r')
			move_right(game);
		else
			move_left(game);
	}
}

void	load_player(t_game *game, char direction)
{
	if (direction == 'u')
		mlx_draw_texture(game->img->player, game->player_up, 0, 0);
	if (direction == 'd')
		mlx_draw_texture(game->img->player, game->player_down, 0, 0);
	if (direction == 'r')
		mlx_draw_texture(game->img->player, game->player_right, 0, 0);
	if (direction == 'l')
		mlx_draw_texture(game->img->player, game->player_left, 0, 0);
}

void	move_player(t_game *game, char line, char direction)
{
	move_select(game, line, direction);
	load_player(game, direction);
}

void	move_hook(mlx_key_data_t keydata, void *data)
{
	t_game	*game;

	game = (t_game *)data;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_player(game, 'y', 'u');
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_player(game, 'y', 'd');
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_player(game, 'x', 'r');
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_player(game, 'x', 'l');
}
