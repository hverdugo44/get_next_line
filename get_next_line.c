/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heverdug <heverdug@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 13:47:23 by heverdug          #+#    #+#             */
/*   Updated: 2025/10/24 11:43:41 by heverdug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clean_line(char *buff)
{
	int		i;
	char	*str;

	i = 0;
	if (!buff)
		return (NULL);
	while (buff[i] && buff[i] != 10)
		i++;
	if (buff[i] != 0)
		i++;
	str = (char *)ft_calloc(i + 1, 1);
	if (!str)
		return (NULL);
	while (--i >= 0)
		str[i] = buff[i];
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
		return ((char *)s2);
	i = -1;
	j = -1;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = 0;
	free(s1);
	free(s2);
	return (str);
}

char	*find_sl(char *buff, int fd)
{
	char	*tmp;
	int		rd;

	while (!ft_strchr(buff, 10))
	{
		tmp = (char *)ft_calloc(BUFFER_SIZE + 1, 1);
		if (!tmp)
		{
			free(buff);
			return (NULL);
		}
		rd = read(fd, tmp, BUFFER_SIZE);
		if (rd < 1)
		{
			free(tmp);
			if (rd < 0)
			{
				free(buff);
				return (NULL);
			}
			return (buff);
		}
		buff = ft_strjoin(buff, tmp);
	}
	return (buff);
}

char	*clean_buff(char *buff)
{
	int		i;
	char	*str;

	i = 0;
	if (!buff)
		return (NULL);
	while (buff[i] && buff[i] != 10)
		i++;
	if (buff[i] == 0)
		str = NULL;
	else
		str = ft_strdup(&buff[i + 1]);
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buff = NULL;
	char		*resultado;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buff = find_sl(buff, fd);
	resultado = clean_line(buff);
	buff = clean_buff(buff);
	return (resultado);
}
