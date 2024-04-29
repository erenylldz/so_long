/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:37:21 by eryildiz          #+#    #+#             */
/*   Updated: 2024/04/22 19:50:17 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*s2;

	s2 = malloc(sizeof(char) * ft_strlen(str) + 1);
	i = 0;
	if (!s2)
		return (0);
	while (str[i])
	{
		s2[i] = str[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*c;
	size_t	i;
	size_t	length;

	length = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start >= length || length == 0 || len == 0)
		return (ft_strdup(""));
	if (len > length - start)
		len = length - start;
	c = malloc(sizeof(char) * (len + 1));
	if (!c)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		c[i] = s[start + i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

size_t	len(char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

char	**ft_split(char *s, char c)
{
	size_t		start;
	size_t		end;
	size_t		str_i;
	char		**str;

	start = 0;
	str_i = 0;
	str = (char **)malloc(sizeof(char *) * (len(s, c) + 1));
	if (!str)
		return (NULL);
	while (s[start])
	{
		while (s[start] && s[start] == c)
			start++;
		end = start;
		while (s[end] && s[end] != c)
			end++;
		if (str_i == len(s, c))
			break ;
		str[str_i++] = ft_substr(s, start, end - start);
		start = end;
	}
	str[str_i] = 0;
	return (str);
}
