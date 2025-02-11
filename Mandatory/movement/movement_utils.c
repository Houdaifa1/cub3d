/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrahm <hdrahm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:42:24 by hdrahm            #+#    #+#             */
/*   Updated: 2025/02/10 12:20:09 by hdrahm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	init_rotation_angle(char d, t_player_info *player_infos)
{
	if (d == 'N')
		player_infos->rotation_angle = 0 + M_PI / 2;
	else if (d == 'S')
		player_infos->rotation_angle = 0 + 3 * (M_PI / 2);
	else if (d == 'E')
		player_infos->rotation_angle = 0 + M_PI;
	else if (d == 'W')
		player_infos->rotation_angle = 0;
}

char	get_player_pos_and_dir(t_player_info *player_infos)
{
	int		i;
	int		j;
	char	d;

	j = 0;
	while (j < player_infos->map_height)
	{
		i = 0;
		while (i < player_infos->map_width)
		{
			d = player_infos->map[j][i];
			if (d == 'N' || d == 'S' || d == 'E' || d == 'W')
			{
				player_infos->i = (i + 0.5) * CUB_SIZE;
				player_infos->j = (j + 0.5) * CUB_SIZE;
				return (d);
			}
			i++;
		}
		j++;
	}
	return (d);
}

int	ray_angle_direction(t_player_info *player_infos)
{
	if (player_infos->wall_hit->hit_direction == 0)
	{
		if (player_infos->ray_rotation_angle > 0
			&& player_infos->ray_rotation_angle < M_PI)
			return (1);
		else
			return (2);
	}
	else
	{
		if (player_infos->ray_rotation_angle > M_PI / 2
			&& player_infos->ray_rotation_angle < 3 * (M_PI / 2))
			return (3);
		else
			return (4);
	}
	return (0);
}
