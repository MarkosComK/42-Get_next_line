/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:37:34 by marsoare          #+#    #+#             */
/*   Updated: 2024/05/12 15:09:09 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	fd = open("test.c", O_RDONLY);
	char *line;
	int	i = 0;
	while (i <= 10)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i++;
	}
	return (0);
}
