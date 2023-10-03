#include "get_next_line.h"

char        *ft_prepare_current_line(char *string);
char        *ft_prepare_next_line(char *string);

char    *get_next_line(int fd) {

    char            buff[BUFFER_SIZE + 1];
    ssize_t         chars_read;
    static  char    *next_line;
    char            *line;

    if ((fd < 0 || fd > 10240) || BUFFER_SIZE <= 0)
	    return (0);
	chars_read = 1;
    while (!(ft_strchr(next_line, '\n')) && chars_read != '\0')
    {
        chars_read = read(fd, buff, BUFFER_SIZE);
        if (chars_read == -1)
			return (NULL);
        buff[chars_read] = '\0';
        next_line = ft_strjoin(next_line, buff);
    }
    line = ft_prepare_current_line(next_line);
    next_line = ft_prepare_next_line(next_line);
    if (line[0] == '\0'){
        free(line);
        return (NULL);
    } 
    return (line);
}

char    *ft_prepare_current_line(char *string) 
{
    int     i = 0;
    char    *current_line;

    while (string[i] != '\n' && string[i] != '\0')
        i++;
    current_line = (char *)malloc((i + 2) * sizeof(char));
    if (current_line == NULL)
        return (NULL);
    i = 0;
    while (string[i] != '\n' && string[i] != '\0')
    {
        current_line[i] = string[i];
        i++;
    }
    if (string[i] == '\n')
        current_line[i++] = '\n';
    current_line[i] = '\0';
    return (current_line);
}

char    *ft_prepare_next_line(char *string)
{
    int         i = 0, j = 0;
    char        *next_line;
    while (string[i] != '\0' && string[i] != '\n')
        i++;
    if (!string[i])
	{
		free(string);
		return (0);
	}
    next_line = (char *)malloc((ft_strlen(string) - i) * sizeof(char));
    if (next_line == NULL)
        return (NULL);
    i++;
    while (string[i] != '\0')
        next_line[j++] = string[i++];
    next_line[j] = '\0';
    free(string);
    return (next_line);
}