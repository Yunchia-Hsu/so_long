/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_string_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:28:34 by yhsu              #+#    #+#             */
/*   Updated: 2024/03/12 13:04:12 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_moves( t_game *game)
{
	char	*string;

	string = ft_itoa(game->steps);
	mlx_delete_image(game->mlx, game->img->moves_nbr);
	game->img->moves_nbr = mlx_put_string(game->mlx, string,
			80, game->height * 64 - 45);
	ft_printf("MOVES: %s\n", string);
	free(string);
}

void	print_eyeball(t_game *game)
{
	char	*string;

	string = ft_itoa(game->collected + 1);
	mlx_delete_image(game->mlx, game->img->eyeball_nbr);
	game->img->eyeball_nbr = mlx_put_string(game->mlx, string,
			160, game->height * 64 - 45);
	free(string);
}

void	string_to_screen(t_game *game)// show string on the screen
{
	game->img->moves_print = mlx_put_string(game->mlx,
			"MOVES", 16, game->height * 64 - 45);
	mlx_image_to_window(game->mlx, game->img->eyeball,
		105, game->height * 64 - 63);
	mlx_put_string(game->mlx, ":", 160, game->height * 64 - 45);
}
