/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:06:39 by marsoare          #+#    #+#             */
/*   Updated: 2024/05/17 16:26:56 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_read(int fd, char *backup);
char	*get_line(char *vault);
char	*get_rest(char *backup);

char	*get_next_line(int fd)
{
	char		*line;
	static char	*backup;

	if (!backup)
		backup = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	backup = get_read(fd, backup);
	line = get_line(backup);
	backup = get_rest(backup);
	return (line);
}

char	*get_read(int fd, char *backup)
{
	int		check_read;
	char	*buf;
	char	*tmp;

	buf = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	check_read = 1;
	while (!(ft_strchr(backup, '\n')) && check_read != 0)
	{
		check_read = read(fd, buf, BUFFER_SIZE);
		if (check_read == -1)
		{
			free(buf);
			free(backup);
			return (NULL);
		}
		buf[check_read] = 0;
		tmp = backup;
		backup = ft_strjoin(tmp, buf);
		free(tmp);
	}
	free(buf);
	return (backup);
}

char	*get_line(char *backup)
{
	int		i;
	char	*line;

	i = 0;
	if (!backup[i])
		return (NULL);
	while (backup[i] && (backup[i] != '\n'))
		i++;
	line = ft_calloc(sizeof(char), (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (backup[i] && (backup[i] != '\n'))
	{
		line[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
	{
		line[i] = backup[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_rest(char *backup)
{
	int		i;
	int		rest_i;
	char	*rest;

	i = 0;
	while (backup[i] && (backup[i] != '\n'))
		i++;
	if (!backup[i])
	{
		free(backup);
		return (NULL);
	}
	rest = malloc(sizeof(char) * (ft_strlen(backup) - i + 1));
	if (!rest)
	{
		free(rest);
		return (NULL);
	}
	++i;
	rest_i = 0;
	while (backup[i])
		rest[rest_i++] = backup[i++];
	rest[rest_i] = '\0';
	free(backup);
	return (rest);
}
