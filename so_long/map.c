/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:39:06 by eryildiz          #+#    #+#             */
/*   Updated: 2024/04/27 18:05:26 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_game *so_long)
{
	int	x;
	int	y;

	so_long->img.player = mlx_xpm_file_to_image(so_long->mlx, "xpm/yoda.xpm",
			&x, &y);
	if (!so_long->img.player)
		return (ft_str("Please check the player image\n"), ft_error(so_long));
	so_long->img.e = mlx_xpm_file_to_image(so_long->mlx, "xpm/exit.xpm",
			&x, &y);
	if (!so_long->img.e)
		return (ft_str("Please check the exit images\n"), ft_error(so_long));
	so_long->img.c = mlx_xpm_file_to_image(so_long->mlx, "xpm/star.xpm",
			&x, &y);
	if (!so_long->img.c)
		return (ft_str("Please check the collectible image\n"),
			ft_error(so_long));
	so_long->img.zero = mlx_xpm_file_to_image(so_long->mlx, "xpm/br.xpm",
			&x, &y);
	if (!so_long->img.zero)
		return (ft_str("Please check the background images\n"),
			ft_error(so_long));
	so_long->img.wall = mlx_xpm_file_to_image(so_long->mlx, "xpm/wall.xpm",
			&x, &y);
	if (!so_long->img.wall)
		return (ft_str("Please check the wall images\n"), ft_error(so_long));
}

void	add_image(t_game *so_long, char c, int x, int y)
{
	if (c == '0')
		mlx_put_image_to_window(so_long->mlx, so_long->window,
			so_long->img.zero, x, y);
	if (c == '1')
		mlx_put_image_to_window(so_long->mlx, so_long->window,
			so_long->img.wall, x, y);
	if (c == 'P')
		mlx_put_image_to_window(so_long->mlx, so_long->window,
			so_long->img.player, x, y);
	if (c == 'C')
		mlx_put_image_to_window(so_long->mlx, so_long->window,
			so_long->img.c, x, y);
	if (c == 'E')
		mlx_put_image_to_window(so_long->mlx, so_long->window,
			so_long->img.e, x, y);
}

static void	add_image_t(t_game *so_long, int x, int y)
{
	mlx_put_image_to_window(so_long->mlx, so_long->window,
		so_long->img.zero, x, y);
}

void	put_pixel(t_game *so_long)
{
	int	x;
	int	y;

	y = 0;
	while (y < so_long->map_loc.y)
	{
		x = 0;
		while (x < so_long->map_loc.x)
		{
			add_image_t(so_long, x * 64, y * 64);
			x++;
		}
		y++;
	}
	y = 0;
	while (y < so_long->map_loc.y)
	{
		x = 0;
		while (x < so_long->map_loc.x)
		{
			add_image(so_long, so_long->map[y][x], x * 64, y * 64);
			x++;
		}
		y++;
	}
}
