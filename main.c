/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:05:58 by marsoare          #+#    #+#             */
/*   Updated: 2024/05/19 16:17:59 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int fd = open("texto.c", O_RDONLY);
	char	*line;
	while ((line = get_next_line(fd)))
	{
		if (!line)
			break;
		printf("%s", line);
		free(line);
	}
	return (0);
}
