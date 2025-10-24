#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*ft_strjoin(char *s1, char *s2);
char	*find_sl(char *buff, int fd);
char	*get_next_line(int fd);
size_t	ft_strlen(char const *s);
char	*ft_strchr(char const *s, int c);
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t n, size_t size);

#endif
