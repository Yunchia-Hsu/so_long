/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:05:07 by yhsu              #+#    #+#             */
/*   Updated: 2024/03/13 13:28:07 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc != 2)
		error_message("NoNo. One file  only!", NULL);
	check_file_extension(argv[1]);
	game = initialize_data(argv[1]);
	game->mlx = mlx_init(game->width * PIXELS,
			game->height * PIXELS, "so_long", false);
	if (!game->mlx)
		return (EXIT_FAILURE);
	game->img = initialize_img_struct(game->mlx, game);
	fill_background(game);
	render_map(game);
	string_to_screen(game);
	mlx_key_hook(game->mlx, move_hook, game);
	mlx_loop(game->mlx);
	delete_map(game->grid, game->height);
	free_direction_texture(game);
	free(game->img);
	free(game);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}
