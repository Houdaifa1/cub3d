/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momazouz <momazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:07:58 by momazouz          #+#    #+#             */
/*   Updated: 2025/02/09 12:24:56 by momazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

void	free_path(t_base *game)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (game->path[i])
			free(game->path[i]);
		i++;
	}
}

void	free_texture(t_base *game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (game->textures[i] != NULL)
		{
			free(game->textures[i]);
			game->textures[i] = NULL;
		}
		i++;
	}
}

int	ft_strlen2(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		j;
	char	*dup;

	dup = malloc((ft_strlen2(s1) + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	j = 0;
	while (s1[j] != '\0')
	{
		dup[j] = s1[j];
		j++;
	}
	dup[j] = '\0';
	return (dup);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 != '\0' && *s1 == *s2 && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
