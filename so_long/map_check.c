/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:43:23 by eryildiz          #+#    #+#             */
/*   Updated: 2024/04/27 18:04:39 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall_check(t_game	*so_long, int i, int j)
{
	while (so_long->map[0][i])
	{
		if (so_long->map[0][i] == '1')
			i++;
		else
		{
			ft_str("Please check the walls\n");
			ft_error(so_long);
		}
	}
	i = 0;
	while (so_long->map[j][i])
	{
		if (so_long->map[j][i] == '1')
			i++;
		else
		{
			ft_str("Please check the walls\n");
			ft_error(so_long);
		}
	}
}

void	wall_ch(t_game *so_long)
{
	int	j;
	int	i;
	int	c;

	i = 0;
	c = so_long->map_loc.x - 1;
	j = so_long->map_loc.y - 1;
	wall_check(so_long, i, j);
	i = 1;
	while (so_long->map[i] && i < j)
	{
		if (so_long->map[i][0] == '1' && so_long->map[i][c] == '1')
			i++;
		else
		{
			ft_str("Please check the walls\n");
			ft_error(so_long);
		}
	}
}

int	map_checker(char *map, t_game *so_long)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == 'C')
			so_long->c++;
		if (map[i] == 'P')
			so_long->player++;
		if (map[i] == 'E')
			so_long->e++;
		i++;
	}
	i = 0;
	while (map[i])
	{
		if (map[i] != 'E' && map[i] != 'C' && map[i] != 'P'
			&& map[i] != '1' && map[i] != '0' && map[i] != '\n')
			return (1);
		i++;
	}
	if (so_long->player != 1 || so_long->c == 0 || so_long->e != 1)
		return (1);
	return (0);
}

void	create_map(char *s, t_game *so_long)
{
	int		fd;
	char	*map;

	map = NULL;
	fd = open(s, O_RDONLY, 0777);
	if (fd == -1)
		return (ft_str("Map could not be read\n"), ft_error(so_long));
	map = ft_read(fd);
	close(fd);
	if (map_checker(map, so_long) == 0)
	{
		line_check(map, so_long);
		so_long->map = ft_split(map, '\n');
		so_long->temp = ft_split(map, '\n');
		free(map);
		map_loc(so_long);
		wall_ch(so_long);
		wall_checker(so_long);
	}
	else
	{
		free(map);
		ft_str("İnsufficient character\n");
		ft_error(so_long);
	}
}
