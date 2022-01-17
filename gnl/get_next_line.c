/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 17:32:02 by dramos-p          #+#    #+#             */
/*   Updated: 2021/06/24 17:33:28 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int gnl_check_end_line(char *save)
{
	int i;

	i = 0;
	if (!save)
		return (-1);
	while (save[i] != 0)
	{
		if (save[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char *ft_strchr(const char *s, int c)
{
	size_t i;
	char proc;

	proc = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == proc)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == proc)
		return ((char *)s + i);
	return (0);
}

static int gnl_check_len(char **line, char **save)
{
	char *backup;
	size_t len;
	int i;

	i = gnl_check_end_line(*save);
	len = ft_strlen(*save) - (i + 1);
	*(*save + i) = '\0';
	*line = ft_strdup(*save);
	if (len == 0)
	{
		free(*save);
		*save = NULL;
	}
	else
	{
		backup = ft_strdup(*save + i + 1);
		free(*save);
		*save = backup;
	}
	return (1);
}

static int gnl_return(char **line, char **save)
{
	int i;

	i = gnl_check_end_line(*save);
	if (i >= 0)
		return (gnl_check_len(line, save));
	if (*save)
	{
		*line = *save;
		*save = NULL;
	}
	else
		*line = ft_strdup("");
	return (0);
}

int get_next_line(int fd, char **line)
{
	int lenr;
	// int i;
	static char *save[OPEN_MAX];
	char *buffer;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE <= 0 || !buffer)
		return (-1);

	lenr = read(fd, buffer, BUFFER_SIZE);
	while (lenr > 0)
	{
		buffer[lenr] = '\0';
		if (save[fd] == NULL)
			save[fd] = ft_strdup(buffer);
		else
			save[fd] = ft_strjoin_md(save[fd], buffer);
		if (ft_strchr(save[fd], '\n'))
			break;
		lenr = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (lenr < 0)
		return (-1);
	return (gnl_return(line, &save[fd]));
}
