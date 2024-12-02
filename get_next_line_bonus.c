/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnafiai <bnafiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:09:35 by bnafiai           #+#    #+#             */
/*   Updated: 2024/12/02 16:32:01 by bnafiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_fd(int fd, char *stored)
{
	char	*str;
	ssize_t	sread;
	char	*new_one;

	str = malloc((size_t)BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	sread = read(fd, str, BUFFER_SIZE);
	if (sread <= 0)
	{
		free(str);
		return (NULL);
	}
	str[sread] = '\0';
	new_one = my_strjoin(stored, str);
	free(stored);
	free(str);
	return (new_one);
}

static char	*get_line(char *stored)
{
	char	*newline_ptr;
	size_t	index;
	char	*line;
	size_t	i;

	if (!stored || !*stored)
		return (NULL);
	newline_ptr = my_strchar(stored, '\n');
	if (!newline_ptr)
		index = my_strlen(stored);
	else
		index = newline_ptr - stored + 1;
	line = malloc(index + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < index)
	{
		line[i] = stored[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*update_stored(char *stored)
{
	char	*newline;
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	while (stored[i] != '\0' && stored[i] != '\n')
		i++;
	len = my_strlen(stored) - i + 1;
	newline = malloc(len + 1);
	if (!newline)
		return (NULL);
	j = 0;
	if (stored[i] == '\n')
		i++;
	while (stored[i] != '\0')
	{
		newline[j] = stored[i];
		i++;
		j++;
	}
	newline[j] = '\0';
	free(stored);
	return (newline);
}

char	*get_next_line(int fd)
{
	static char		*stored[1024];
	char			*line;
	char			*new_stored;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	while (!my_strchar(stored[fd], '\n'))
	{
		new_stored = read_fd(fd, stored[fd]);
		if (!new_stored)
			break ;
		stored[fd] = new_stored;
	}
	line = get_line(stored[fd]);
	if (!line)
		return (NULL);
	stored[fd] = update_stored(stored[fd]);
	if (stored[fd] && *stored[fd] == '\0')
	{
		free(stored[fd]);
		stored[fd] = NULL;
	}
	return (line);
}
// int main()
// {
// 	int fd = open("test1.txt", O_RDWR);
// 	int fd2 = open("test2.txt", O_RDWR);
// 	char *line, *line2;
// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	line2 = get_next_line(fd2);
// 	while (line2 != NULL)
// 	{
// 		printf("%s", line2);
// 		free(line2);
// 		line2 = get_next_line(fd2);
// 	}
// 	return 0;

// }
