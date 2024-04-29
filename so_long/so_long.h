/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:26:31 by eryildiz          #+#    #+#             */
/*   Updated: 2024/04/27 18:32:36 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include "mlx/mlx.h"
# include <stdio.h>

typedef struct location
{
	int	x;
	int	y;
}				t_loc;

typedef struct images
{
	void	*e;
	void	*player;
	void	*wall;
	void	*zero;
	void	*c;
}				t_images;

typedef struct game
{
	void		*mlx;
	void		*window;
	char		**map;
	char		**temp;
	int			player;
	int			e;
	int			c;
	int			move;
	bool		exit;
	t_loc		map_loc;
	t_loc		player_loc;
	t_loc		e_loc;
	t_images	img;
}				t_game;

int		exit_game(t_game *so_long);
void	coin_check(t_game *so_long);
void	ft_free(t_game *so_long);
int		move_check(char **str);
void	wall_checker(t_game *so_long);
void	line_check(char *str, t_game *so_long);
int		character_check(char *map);
void	player_location(t_game *so_long);
void	exit_location(t_game *so_long);
void	map_loc(t_game *so_long);
void	ft_error(t_game *so_long);
int		move_controler(int x, int y, t_game *so_long);
int		player_move(int key, t_game *so_long);
int		key_control(int key, t_game *so_long);
void	game_start(t_game *so_long);
int		end_game(t_game *so_long);
void	ft_putnbr(int n);
void	wall_check(t_game	*so_long, int i, int j);
void	wall_ch(t_game *so_long);
int		map_checker(char *map, t_game *so_long);
void	create_map(char *s, t_game *so_long);
void	put_image(t_game *game);
void	add_image(t_game *game, char c, int x, int y);
void	put_pixel(t_game *game);
int		move_down(int key, t_game *so_long);
int		move_up(int key, t_game *so_long);
int		move_left(int key, t_game *so_long);
int		move_right(int key, t_game *so_long);
size_t	ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	len(char *str, char c);
char	**ft_split(char *s, char c);
void	game_init(t_game *so_long);
int		ft_strcmp(char *s1, char *s2);
void	arg_check(char *str, t_game *so_long);
char	*ft_read(int fd);
void	ft_str(char *str);
#endif
