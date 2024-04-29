/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:44:24 by eryildiz          #+#    #+#             */
/*   Updated: 2024/04/27 15:23:50 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	character_check(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == 'E' || map[i] == 'C' || map[i] == 'P'
			|| map[i] == '1' || map[i] == '0' || map[i] == '\n')
			i++;
		else
			return (1);
	}
	return (0);
}

void	player_location(t_game *so_long)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j])
		{
			if (so_long->map[i][j] == 'P')
			{
				so_long->player_loc.y = i;
				so_long->player_loc.x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	exit_location(t_game *so_long)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j])
		{
			if (so_long->map[i][j] == 'E')
			{
				so_long->e_loc.y = i;
				so_long->e_loc.x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	map_loc(t_game *so_long)
{
	int	x;
	int	y;

	y = 0;
	while (so_long->map[y] != NULL)
	{
		x = 0;
		while (so_long->map[y][x] != '\0')
			x++;
		y++;
	}
	so_long->map_loc.y = y;
	so_long->map_loc.x = x;
	player_location(so_long);
	exit_location(so_long);
}

void	ft_error(t_game *so_long)
{
	ft_free(so_long);
	exit (1);
}
