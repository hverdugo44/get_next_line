/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:32:36 by hverdugo          #+#    #+#             */
/*   Updated: 2024/08/21 13:01:53 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchar(char	*str, char c)
{
	int	x;

	if (str == NULL)
		return (-1);
	x = 0;
	while (str[x] != 0 && str[x] != c)
		x++;
	if (str[x] == c)
		return (x);
	return (-1);
}

void	ft_bzero(void *str, size_t x)
{
	char	*c;

	c = str;
	while (x > 0)
	{
		c[x - 1] = 0;
		x--;
	}
}

void	*ft_calloc(size_t x, size_t y)
{
	void	*str;

	str = malloc(x * y);
	if (!str)
		return (NULL);
	ft_bzero(str, x * y);
	return (str);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		x;
	char	*dup;

	i = 0;
	x = ft_strlen((char *)s);
	dup = ft_calloc(sizeof(char), x + 1);
	while (i < x)
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL)
		return (ft_strdup(s2));
	str = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	free(s1);
	return (str);
}
