/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:43:43 by eryildiz          #+#    #+#             */
/*   Updated: 2024/04/27 18:32:30 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_game(t_game *so_long)
{
	mlx_destroy_window(so_long->mlx, so_long->window);
	ft_free(so_long);
	exit(0);
}

void	ft_putnbr(int n)
{
	long	number;
	char	c;

	number = n;
	if (number < 0)
	{
		write(1, "-", 1);
		number = number * -1;
	}
	if (number < 10)
	{
		c = number + 48;
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(number / 10);
		ft_putnbr(number % 10);
	}
}

int	main(int ac, char **av)
{
	t_game	*so_long;

	so_long = (t_game *)malloc(sizeof(t_game));
	if (!so_long)
		return (0);
	if (ac == 2 && av[1] && av[1][0] != '.')
	{
		game_start(so_long);
		arg_check(av[1], so_long);
		create_map(av[1], so_long);
		if (so_long->map_loc.x > 40 || so_long->map_loc.y > 21)
		{
			ft_str("Please draw a smaller map\n");
			ft_error(so_long);
		}
		game_init(so_long);
	}
	else
	{
		free(so_long);
		write(1, "Please add map\n", 16);
		exit(1);
	}
}
