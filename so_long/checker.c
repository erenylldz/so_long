/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:44:29 by eryildiz          #+#    #+#             */
/*   Updated: 2024/04/27 18:04:03 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(t_game *so_long)
{
	int	i;

	i = -1;
	if (so_long->map)
		while (so_long->map[++i])
			free(so_long->map[i]);
	i = -1;
	if (so_long->temp)
		while (so_long->temp[++i])
			free(so_long->temp[i]);
	if (so_long->map)
		free(so_long->map);
	if (so_long->temp)
		free(so_long->temp);
	so_long->c = 0;
	so_long->player = 0;
	so_long->e = 0;
	so_long->map = 0;
	so_long->temp = 0;
	free (so_long);
	so_long = NULL;
}

static void	ft_flood_fill(int x, int y, t_game *so_long)
{
	if (x < 0 || x > so_long->map_loc.x - 1
		|| y < 0 || y > so_long->map_loc.y - 1)
		return ;
	if (so_long->temp[y][x] != '1' && so_long->temp[y][x] != 'F')
	{
		so_long->temp[y][x] = 'F';
		ft_flood_fill(x, y - 1, so_long);
		ft_flood_fill(x, y + 1, so_long);
		ft_flood_fill(x - 1, y, so_long);
		ft_flood_fill(x + 1, y, so_long);
	}
}

int	move_check(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'E' || str[i][j] == 'C' || str[i][j] == 'P')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	wall_checker(t_game *so_long)
{
	int	i;
	int	j;

	j = 0;
	while (so_long->map[j])
	{
		i = 0;
		while (so_long->map[j][i])
			i++;
		if (i != so_long->map_loc.x)
		{
			ft_str("Please check the walls\n");
			ft_error(so_long);
		}
		j++;
	}
	ft_flood_fill(so_long->player_loc.x, so_long->player_loc.y, so_long);
	if (move_check(so_long->temp) == 1)
	{
		ft_str("There are inaccessible places on the map\n");
		ft_error(so_long);
	}
}

void	line_check(char *str, t_game *so_long)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[0] == '\n'
			|| (str[i] == '\n' && str[i + 1] && str[i + 1] == '\n')
			|| (str[i] == '\n' && (str[i + 1] == '\0')))
		{
			ft_str("Please check the newlines\n");
			ft_error(so_long);
		}
		i++;
	}
}
