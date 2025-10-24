#include "get_next_line.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*ptr;
	long	i;

	i = n * size;
	ptr = (char *)malloc(i);
	if (!ptr)
		return (NULL);
	while (--i >= 0)
		ptr[i] = 0;
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

	if (!s)
		return (NULL);
	cpy = (unsigned char *)s;
	i = 0;
	while (cpy[i])
	{
		if (cpy[i] == (unsigned char)c)
			return ((char *)&cpy[i]);
		i++;
	}
	return (NULL);
}
