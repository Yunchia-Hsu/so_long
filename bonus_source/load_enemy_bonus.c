/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:36:41 by yhsu              #+#    #+#             */
/*   Updated: 2024/03/12 13:07:15 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_img	*load_enemy_texture(mlx_t *mlx, t_img *img, t_game *game)
{
	mlx_texture_t	*enemy;

	enemy = mlx_load_png("./sprites/enemy.png");
	if (!enemy)
		error_message("Problem with loading png11", game);
	img->enemy[0] = mlx_texture_to_image(mlx, enemy);
	if (!img->enemy[0])
		error_message("Problem with texture to image12", game);
	mlx_delete_texture (enemy);
	return (img);
}

t_img	*load_enemy_up_texture( mlx_t *mlx, t_img *img, t_game *game)
{
	mlx_texture_t	*enemy_up;

	enemy_up = mlx_load_png("./sprites/enemy_up.png");
	if (!enemy_up)
		error_message("Problem with loading pngenemy_up", game);
	img->enemy[1] = mlx_texture_to_image(mlx, enemy_up);
	if (!img->enemy[1])
		error_message("Problem with texture to image2", game);
	mlx_delete_texture (enemy_up);
	return (img);
}

t_img	*load_enemy_down_texture(mlx_t *mlx, t_img *img, t_game *game)
{
	mlx_texture_t	*enemy_down;

	enemy_down = mlx_load_png("./sprites/enemy_down.png");
	if (!enemy_down)
		error_message("Problem with loading png enemy_down", game);
	img->enemy[2] = mlx_texture_to_image(mlx, enemy_down);
	if (!img->enemy[2])
		error_message("Problem with texture to enemy_down", game);
	mlx_delete_texture (enemy_down);
	return (img);
}
