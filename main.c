/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:37:34 by marsoare          #+#    #+#             */
/*   Updated: 2024/05/11 16:45:18 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	fd = open("test.c", O_RDONLY);
	char *line = get_next_line(fd);
	while (line = get_next_line(fd))
	{
		printf("%s", line);
	}
	return (0);
}
