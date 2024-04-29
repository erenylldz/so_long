/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:44:20 by eryildiz          #+#    #+#             */
/*   Updated: 2024/04/22 17:03:25 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_game *so_long)
{
	if (so_long->player_loc.x == so_long->e_loc.x
		&& so_long->player_loc.y == so_long->e_loc.y)
		return (0);
	return (1);
}

void	coin_check(t_game *so_long)
{
	int	x;
	int	y;
	int	coin;

	y = 1;
	coin = 0;
	while (so_long->map[y])
	{
		x = 1;
		while (so_long->map[y][x])
		{
			if (so_long->map[y][x] == 'C')
				coin++;
			x++;
		}
		y++;
	}
	player_location(so_long);
	if (coin == 0 && exit_game(so_long) == 0)
	{
		write (1, "\nYODA\n", 6);
		end_game(so_long);
	}
}
