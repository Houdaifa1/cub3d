/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprit_animation_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrahm <hdrahm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:21:22 by momazouz          #+#    #+#             */
/*   Updated: 2025/02/10 16:06:41 by hdrahm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	initialize_frames(t_base *game)
{
	int	i;

	i = 0;
	while (i < game->weapon_sprite->frame_count)
	{
		game->weapon_sprite->frames[i] = NULL;
		i++;
	}
}

void	draw_weapon_sprite(t_base *game, t_sprite *sprite)
{
	int				x;
	int				y;
	unsigned int	color;
	t_image_data	img_data;

	y = 0;
	img_data.current_frame_img = sprite->frames[sprite->current_frame];
	img_data.frame_data = (char *)mlx_get_data_addr(img_data.current_frame_img,
			&img_data.bpp, &img_data.line_length, &img_data.endian);
	while (y < sprite->height)
	{
		x = 0;
		while (x < sprite->width)
		{
			color = *(unsigned int *)(img_data.frame_data + (y
						* img_data.line_length + x * (img_data.bpp / 8)));
			if (color != 0xFF000000)
				my_mlx_pixel_put(game, sprite->x + x - sprite->width / 2,
					sprite->y + y, color);
			x++;
		}
		y++;
	}
}

void	*load_single_frame(t_base *game, char *path)
{
	void	*image;

	image = mlx_xpm_file_to_image(game->mlx_ptrs->mlx_ptr, path,
			&game->weapon_sprite->width, &game->weapon_sprite->height);
	return (image);
}

void	load_sprite_frames(char **paths, int frame_count, t_base *game)
{
	int	i;

	game->weapon_sprite->frame_count = frame_count;
	game->weapon_sprite->frames = malloc(frame_count * sizeof(void *));
	if (!game->weapon_sprite->frames)
	{
		ft_printf_err("Error\nFailed to allocate memory for sprite frames\n");
		error_texture_animation(game);
		exit(1);
	}
	initialize_frames(game);
	i = 0;
	while (i < frame_count)
	{
		game->weapon_sprite->frames[i] = load_single_frame(game, paths[i]);
		if (!game->weapon_sprite->frames[i])
		{
			ft_printf_err("Error\nFailed to load animation texture\n");
			error_texture_animation(game);
			exit(1);
		}
		i++;
	}
}

void	init_weapon_sprite(t_base *game)
{
	static char	*weapon_sprite_paths[] = {"texture/sprit/sprite_frame1.xpm",
		"texture/sprit/sprite_frame2.xpm",
		"texture/sprit/sprite_frame3.xpm",
		"texture/sprit/sprite_frame4.xpm",
		"texture/sprit/sprite_frame5.xpm",
		"texture/sprit/sprite_frame6.xpm",
		"texture/sprit/sprite_frame7.xpm",
		"texture/sprit/sprite_frame8.xpm",
		"texture/sprit/sprite_frame9.xpm",
		"texture/sprit/sprite_frame10.xpm",
		"texture/sprit/sprite_frame11.xpm"};

	game->weapon_sprite = malloc(sizeof(t_sprite));
	load_sprite_frames(weapon_sprite_paths, 11, game);
	game->weapon_sprite->x = SCREEN_SIZE / 2;
	game->weapon_sprite->y = (SCREEN_HEIGHT - game->weapon_sprite->height) + 1;
	game->weapon_sprite->current_frame = 0;
	game->weapon_sprite->is_animating = 0;
	game->weapon_sprite->frame_timer = 0;
}
