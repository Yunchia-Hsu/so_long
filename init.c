/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:24:21 by yhsu              #+#    #+#             */
/*   Updated: 2024/03/12 19:07:29 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*initialize_img_struct(mlx_t *mlx, t_game *game)
{
	t_img	*assets;

	assets = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!assets)
		return (NULL);
	assets = load_tree_texture(mlx, assets, game);
	assets = load_gravestone_texture(mlx, assets, game);
	assets = load_eyeball_texture(mlx, assets, game);
	assets = load_player_texture(mlx, assets, game);
	assets = load_floor_texture(mlx, assets, game);
	return (assets);
}

t_game	*initialize_data(char *str)
{
	char	*map_str;
	char	**map_array;
	t_game	*data;

	map_str = read_map(str);
	if (!map_str)
		error_message("read map failed", NULL);
	check_empty_line(map_str);
	check_map_content(map_str);
	check_map_shape(map_str);
	map_array = ft_split(map_str, '\n');
	if (!map_array)
	{
		free(map_str);
		error_message("map_array failed", NULL);
	}
	check_map_size(map_array);
	data = initialize_game_struct(map_array);
	check_wall(data);
	if (flood_fill(data) == -1)
	{
		free (map_str);
		error_message("strdup failed", data);
	}
	return (free(map_str), data);
}

t_game	*initialize_game_struct(char **grid)
{
	t_game	*game;

	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!game)
		error_message("struct memory allocation faile1", game);
	game->grid = grid;
	game->width = ft_strlen(grid[0]);
	game->height = row_count(grid);
	game->eyeball = count_eyeball(game);
	game->steps = 0;
	game->player_x = get_player_pos(game, 'x');
	game->player_y = get_player_pos(game, 'y');
	game->exit_x = get_exit_pos(game, 'x');
	game->exit_y = get_exit_pos(game, 'y');
	load_other_player_textures(game);
	return (game);
}
