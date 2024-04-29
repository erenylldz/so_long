/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:44:15 by eryildiz          #+#    #+#             */
/*   Updated: 2024/04/27 18:04:13 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_controler(int x, int y, t_game *so_long)
{
	so_long->move++;
	write (1, "step: ", 6);
	ft_putnbr(so_long->move);
	write (1, "\n", 1);
	if (so_long->map[y][x] == '1')
		return (0);
	return (1);
}

int	player_move(int key, t_game *so_long)
{
	if (move_up(key, so_long) == 0)
		return (0);
	else if (move_down(key, so_long) == 0)
		return (0);
	else if (move_left(key, so_long) == 0)
		return (0);
	else if (move_right(key, so_long) == 0)
		return (0);
	return (1);
}

int	key_control(int key, t_game *so_long)
{
	if (player_move(key, so_long) == 0)
		return (0);
	else if (key == 53)
		end_game(so_long);
	return (1);
}

void	game_init(t_game *so_long)
{
	so_long->mlx = mlx_init();
	if (!so_long->mlx)
	{
		ft_str("Game failed to open\n");
		ft_error(so_long);
	}
	so_long->window = mlx_new_window(so_long->mlx, so_long->map_loc.x * 64,
			so_long->map_loc.y * 64, "so_long");
	if (!so_long->window)
	{
		ft_str("Window failed to open\n");
		ft_error(so_long);
	}
	put_image(so_long);
	put_pixel(so_long);
	mlx_key_hook(so_long->window, key_control, so_long);
	mlx_hook(so_long->window, 17, 2, end_game, so_long);
	mlx_loop(so_long->mlx);
}

void	game_start(t_game *so_long)
{
	so_long->map = NULL;
	so_long->temp = NULL;
	so_long->mlx = NULL;
	so_long->window = NULL;
	so_long->img.player = NULL;
	so_long->img.e = NULL;
	so_long->img.c = NULL;
	so_long->img.wall = NULL;
	so_long->img.zero = NULL;
	so_long->exit = false;
	so_long->player = 0;
	so_long->c = 0;
	so_long->e = 0;
	so_long->move = 0;
}
