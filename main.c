/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:37:34 by marsoare          #+#    #+#             */
/*   Updated: 2024/05/17 20:24:19 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	fd = open("test.c", O_RDONLY);
	char *line;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (!line)
			break;
		printf("%s", line);
		free(line);
	}
	return (0);
}
/*
#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int     fd1;
    int     fd2;
    char    *file1 = "./texto.c";
    char    *file2 = "./texto2.c";
    char    *str;

    fd1 = open(file1, O_RDONLY);
    fd2 = open(file2, O_RDONLY);
    str = "";
    fd1 = 42;
    fd2 = 42;
    while (str)
    {
        str = get_next_line(fd1);
        printf ("%s", str);
        free(str);
        str = get_next_line(fd2);
        printf ("%s", str);
        free(str);
    }
    close(fd1);
    return (0);
}
*/
