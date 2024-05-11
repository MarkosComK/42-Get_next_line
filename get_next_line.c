/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:06:39 by marsoare          #+#    #+#             */
/*   Updated: 2024/05/11 18:03:20 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(int fd, char *buf, char *backup);

char	*get_next_line(int fd)
{
	char	*line;
	char	*buf;
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
	check_read = read(fd, buf, BUFFER_SIZE);
	line = buf;
	return (line);
}
