/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrahm <hdrahm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:42:21 by hdrahm            #+#    #+#             */
/*   Updated: 2025/02/07 10:10:28 by hdrahm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	get_angle_from_side(t_player_info *player_infos, int d)
{
	if (d == 1 || d == 2)
	{
		if (d == 1 && player_infos->ray_rotation_angle > M_PI / 2)
			player_infos->ray_rotation_angle = M_PI;
		if (d == 2 && player_infos->ray_rotation_angle < (M_PI / 2) * 3)
			player_infos->ray_rotation_angle = M_PI;
		else
			player_infos->ray_rotation_angle = 0;
	}
	else if (d == 3 || d == 4)
	{
		if (d == 3 && player_infos->ray_rotation_angle > M_PI)
			player_infos->ray_rotation_angle = (M_PI / 2) * 3;
		if (d == 4 && player_infos->ray_rotation_angle > (M_PI / 2) * 3)
			player_infos->ray_rotation_angle = (M_PI / 2) * 3;
		else
			player_infos->ray_rotation_angle = M_PI / 2;
	}
}

void	update_position(t_player_info *player_infos, int sign, double speed,
		double angle)
{
	if (sign == 1)
	{
		player_infos->i = player_infos->i + cos(player_infos->rotation_angle
				+ angle) * speed;
		player_infos->j = player_infos->j + sin(player_infos->rotation_angle
				+ angle) * speed;
	}
	else
	{
		player_infos->i = player_infos->i - cos(player_infos->rotation_angle)
			* speed;
		player_infos->j = player_infos->j - sin(player_infos->rotation_angle)
			* speed;
	}
}

void	update_angle(t_player_info *player_infos, int sign, double angle)
{
	if (sign == 1)
	{
		angle += player_infos->rotation_angle;
		player_infos->rotation_angle = normalize_angle(angle);
	}
	else
	{
		angle = player_infos->rotation_angle - angle;
		player_infos->rotation_angle = normalize_angle(angle);
	}
}

void	do_the_magic(t_base *game)
{
	rendering_3d(game);
	mlx_put_image_to_window(game->mlx_ptrs->mlx_ptr, game->mlx_ptrs->win,
		game->mlx_ptrs->img, 0, 0);
}
