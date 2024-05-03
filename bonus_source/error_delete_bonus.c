/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_delete_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:16:43 by yhsu              #+#    #+#             */
/*   Updated: 2024/03/12 19:08:16 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error_message(char *str, t_game *game)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(str, 2);
	if (game)
	{
		if (game->grid)
			delete_map(game->grid, game->height);
		if (game->player_up || game->player_down
			|| game->player_left || game->player_right)
			free_direction_texture(game);
		if (game->img)
			free(game->img);
		if (game)
			free(game);
		if (game->mlx)
			mlx_terminate(game->mlx);
	}
	exit(1);
}

void	delete_map(char **grid, int32_t height)
{
	int	i;

	i = 0;
	while (i < height)
		free(grid[i++]);
	free(grid);
}

void	free_direction_texture(t_game *game)
{
	if (game->player_down)
		mlx_delete_texture(game->player_down);
	if (game->player_up)
		mlx_delete_texture(game->player_up);
	if (game->player_left)
		mlx_delete_texture(game->player_left);
	if (game->player_right)
		mlx_delete_texture(game->player_right);
}
