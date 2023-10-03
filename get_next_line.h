#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 2
#endif

char        *get_next_line(int fd);
char        *ft_prepare_current_line(char *string);
char        *ft_prepare_next_line(char *string);
char        *ft_strjoin(char *s1, char *s2);
void	    *ft_memcpy(void *dst, const void *src, size_t n);
char	    *ft_strchr(char *s, int c);
size_t      ft_strlen(char *s);

#endif