/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momazouz <momazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:50:56 by momazouz          #+#    #+#             */
/*   Updated: 2025/02/08 11:51:03 by momazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

void	load_texture(t_base *game, t_texture *texture, char *path)
{
	texture->img_ptr = mlx_xpm_file_to_image(game->mlx_ptrs->mlx_ptr, path,
			&texture->width, &texture->height);
	if (!texture->img_ptr)
	{
		ft_printf_err("Error\nFailed to load texture:\n");
		error_texture_exit(game);
		exit(1);
	}
	texture->data = (int *)mlx_get_data_addr(texture->img_ptr, &texture->bpp,
			&texture->line_length, &texture->endian);
	if (!texture->data)
	{
		ft_printf_err("Error\nFailed to get texture data for: \n");
		error_texture_exit(game);
		exit(1);
	}
}

void	load_all_textures(t_base *game)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (game->textures[i] != NULL && game->path[i] != NULL)
			load_texture(game, game->textures[i], game->path[i]);
		i++;
	}
}
