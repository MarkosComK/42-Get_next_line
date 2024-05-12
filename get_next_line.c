/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:06:39 by marsoare          #+#    #+#             */
/*   Updated: 2024/05/12 15:23:56 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(int fd, char *buf, char *backup);

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*backup;

	buf = malloc(sizeof(char) + (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = get_line(fd, buf, backup);
	free(buf);
	return (line);
}

char	*get_line(int fd, char *buf, char *backup)
{
	int		check_read;
	char	*tmp;

	check_read = 1;
	backup = ft_strdup("");
	while (!(ft_strchr(backup, '\n')) || check_read < 0)
	{
		check_read = read(fd, buf, BUFFER_SIZE);
		if (check_read < 0)
			return (NULL);
		buf[BUFFER_SIZE] = 0;
		tmp = backup;
		backup = ft_strjoin(tmp, buf);
		free(tmp);
	}
	return (backup);
}
