/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrahm <hdrahm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:20:56 by hdrahm            #+#    #+#             */
/*   Updated: 2025/02/07 10:20:57 by hdrahm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int ac, char **av)
{
	t_base	game;

	if (ac != 2)
		return (1);
	ft_init_struct_game(&game);
	parsing(&game, av[1]);
	initialize_game(&game);
	return (0);
}
