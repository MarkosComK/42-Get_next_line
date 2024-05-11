/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:06:39 by marsoare          #+#    #+#             */
/*   Updated: 2024/05/11 18:40:41 by marsoare         ###   ########.fr       */
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
}

char	*get_line(int fd, char *buf, char *backup)
{
	char	*line;
	int		check_read;

	check_read = 1;
	do
	{
		check_read = read(fd, buf, BUFFER_SIZE);
		backup = ft_strdup("");
		backup = ft_strjoin(backup, buf);
	} while (!ft_strchr(backup, '\n'));
	line = backup;
	return (line);
}
