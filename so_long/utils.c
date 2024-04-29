/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:37:11 by eryildiz          #+#    #+#             */
/*   Updated: 2024/04/29 16:52:32 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (i);
	}
	return (0);
}

void	arg_check(char *str, t_game *so_long)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '.')
			i++;
		else
			break ;
	}
	if (ft_strcmp(str + i, ".ber") == 1)
	{
		ft_str("File extension is not correct");
		ft_error(so_long);
	}
}

static char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s3;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	s3 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	i = -1;
	while (s1[++i] != 0)
		s3[i] = s1[i];
	j = -1;
	while (s2[++j] != 0)
		s3[i + j] = s2[j];
	s3[i + j] = '\0';
	free(s1);
	return (s3);
}

char	*ft_read(int fd)
{
	char	*liner;
	char	*str;
	int		rd;
	int		size;

	size = 50;
	liner = malloc(sizeof(char) * (size + 1));
	rd = 1;
	if (!liner)
		return (NULL);
	while (rd > 0)
	{
		rd = read(fd, liner, size);
		if (rd < 0)
		{
			free(liner);
			return (NULL);
		}
		liner[rd] = '\0';
		if (rd > 0)
			str = ft_strjoin(str, liner);
	}
	liner[ft_strlen(liner) - 1] = '\0';
	free(liner);
	return (str);
}

void	ft_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}
