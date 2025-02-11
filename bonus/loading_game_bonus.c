/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_game_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momazouz <momazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:48:06 by momazouz          #+#    #+#             */
/*   Updated: 2025/02/08 11:43:50 by momazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	change_map_and_dup(t_base *game)
{
	int	j;
	int	i;

	j = 0;
	game->player_infos->map2 = malloc(sizeof(char *) * game->map_height);
	while (j < game->map_height)
	{
		i = 0;
		game->player_infos->map2[j] = ft_strdup(game->map[j]);
		while (i < game->map_width)
		{
			if (game->map[j][i] == 'D')
				game->map[j][i] = '1';
			i++;
		}
		j++;
	}
}

void	init_player_infos(t_player_info *player_infos, t_base *game,
		t_wall_hit *wall_hit)
{
	player_infos->wall_hit = wall_hit;
	player_infos->map = game->map;
	player_infos->map_width = game->map_width;
	player_infos->map_height = game->map_height;
	player_infos->rotation_speed = R_SPEED * (M_PI / 180);
	player_infos->move_speed = P_SPEED;
}

void	ft_mlx_hood_key_mouse_exit(t_mlx_ptrs *mlx_ptrs, t_base *game)
{
	mlx_hook(mlx_ptrs->win, 2, 1L << 0, key_press, game);
	mlx_hook(mlx_ptrs->win, 3, 1L << 1, key_release, game);
	mlx_hook(mlx_ptrs->win, 4, 1L << 2, mouse_press, game);
	mlx_hook(mlx_ptrs->win, 5, 1L << 3, mouse_release, game);
	mlx_hook(mlx_ptrs->win, 17, 0L, exit_game, game);
}

void	initialize_game(t_base *game)
{
	t_mlx_ptrs		mlx_ptrs;
	t_player_info	player_infos;
	t_wall_hit		wall_hit;

	mlx_ptrs.mlx_ptr = mlx_init();
	mlx_ptrs.win = mlx_new_window(mlx_ptrs.mlx_ptr, SCREEN_SIZE, SCREEN_HEIGHT,
			"Cub3D");
	mlx_ptrs.img = mlx_new_image(mlx_ptrs.mlx_ptr, SCREEN_SIZE, SCREEN_HEIGHT);
	mlx_ptrs.addr = mlx_get_data_addr(mlx_ptrs.img, &mlx_ptrs.bpp,
			&mlx_ptrs.line_length, &mlx_ptrs.endian);
	game->mlx_ptrs = &mlx_ptrs;
	load_all_textures(game);
	init_weapon_sprite(game);
	initialize_keys(game);
	init_player_infos(&player_infos, game, &wall_hit);
	game->player_infos = &player_infos;
	change_map_and_dup(game);
	init_rotation_angle(get_player_pos_and_dir(&player_infos), &player_infos);
	rendering_3d(game);
	draw_minimap(game);
	draw_weapon_sprite(game, game->weapon_sprite);
	mlx_put_image_to_window(mlx_ptrs.mlx_ptr, mlx_ptrs.win, mlx_ptrs.img, 0, 0);
	ft_mlx_hood_key_mouse_exit(&mlx_ptrs, game);
	mlx_loop_hook(game->mlx_ptrs->mlx_ptr, game_loop, game);
	mlx_loop(mlx_ptrs.mlx_ptr);
}
