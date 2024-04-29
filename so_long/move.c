/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:38:56 by eryildiz          #+#    #+#             */
/*   Updated: 2024/04/27 18:05:59 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_down(int key, t_game *so_long)
{
	if ((key == 126 || key == 13)
		&& move_controler(so_long->player_loc.x,
			so_long->player_loc.y - 1, so_long))
	{
		so_long->map[so_long->player_loc.y][so_long->player_loc.x] = '0';
		if (so_long->exit == true)
		{
			so_long->map[so_long->player_loc.y][so_long->player_loc.x] = 'E';
			so_long->exit = false;
		}
		so_long->player_loc.y--;
		so_long->map[so_long->player_loc.y][so_long->player_loc.x] = 'P';
		put_pixel(so_long);
		if (so_long->e_loc.x == so_long->player_loc.x
			&& so_long->player_loc.y == so_long->e_loc.y)
			so_long->exit = true;
		coin_check(so_long);
		return (0);
	}
	return (1);
}

int	move_up(int key, t_game *so_long)
{
	if ((key == 125 || key == 1)
		&& move_controler(so_long->player_loc.x,
			so_long->player_loc.y + 1, so_long))
	{
		so_long->map[so_long->player_loc.y][so_long->player_loc.x] = '0';
		if (so_long->exit == true)
		{
			so_long->map[so_long->player_loc.y][so_long->player_loc.x] = 'E';
			so_long->exit = false;
		}
		so_long->player_loc.y++;
		so_long->map[so_long->player_loc.y][so_long->player_loc.x] = 'P';
		if (so_long->e_loc.x == so_long->player_loc.x
			&& so_long->player_loc.y == so_long->e_loc.y)
			so_long->exit = true;
		put_pixel(so_long);
		coin_check(so_long);
		return (0);
	}
	return (1);
}

int	move_left(int key, t_game *so_long)
{
	if ((key == 123 || key == 0)
		&& move_controler(so_long->player_loc.x - 1,
			so_long->player_loc.y, so_long))
	{
		so_long->map[so_long->player_loc.y][so_long->player_loc.x] = '0';
		if (so_long->exit == true)
		{
			so_long->map[so_long->player_loc.y][so_long->player_loc.x] = 'E';
			so_long->exit = false;
		}
		so_long->player_loc.x--;
		so_long->map[so_long->player_loc.y][so_long->player_loc.x] = 'P';
		if (so_long->e_loc.x == so_long->player_loc.x
			&& so_long->player_loc.y == so_long->e_loc.y)
			so_long->exit = true;
		put_pixel(so_long);
		coin_check(so_long);
		return (0);
	}
	return (1);
}

int	move_right(int key, t_game *so_long)
{
	if ((key == 124 || key == 2)
		&& move_controler(so_long->player_loc.x + 1,
			so_long->player_loc.y, so_long))
	{
		so_long->map[so_long->player_loc.y][so_long->player_loc.x] = '0';
		if (so_long->exit == true)
		{
			so_long->map[so_long->player_loc.y][so_long->player_loc.x] = 'E';
			so_long->exit = false;
		}
		so_long->player_loc.x++;
		so_long->map[so_long->player_loc.y][so_long->player_loc.x] = 'P';
		if (so_long->e_loc.x == so_long->player_loc.x
			&& so_long->player_loc.y == so_long->e_loc.y)
			so_long->exit = true;
		put_pixel(so_long);
		coin_check(so_long);
		return (0);
	}
	return (1);
}
