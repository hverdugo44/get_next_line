#include "get_next_line.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (n == 0 || size == 0)
	{
		ptr = (char *)malloc(1);
		if (!ptr)
			return (NULL);
		ptr[0] = 0;
	}
	else
	{
		ptr = (char *)malloc(n * size);
		if (!ptr)
			return (NULL);
		while (i <= n * size)
		{
			ptr[i] = 0;
			i++;
		}
	}
	return ((void *)ptr);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*cpy;

	i = 0;
	cpy = (char *)ft_calloc(ft_strlen(s) + 1, 1);
	if (!cpy)
		return (NULL);
	while (s[i] != 0)
	{
		cpy[i] = s[i];
		i++;
	}
	return (cpy);
}

size_t	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char const *s, int c)
{
	int				i;
	unsigned char	*cpy;

	cpy = (unsigned char *)s;
	i = 0;
	while (cpy[i])
	{
		if (cpy[i] == (unsigned char)c)
			return ((char *)&cpy[i]);
		i++;
	}
	if (cpy[i] == (unsigned char)c)
		return ((char *)&cpy[i]);
	return (NULL);
}
