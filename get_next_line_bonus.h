/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:07:48 by marsoare          #+#    #+#             */
/*   Updated: 2024/05/18 22:04:06 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FDS
#  define MAX_FDS 4242
# endif

char	*get_next_line(int fd);
char	*get_read(int fd, char *backup);
char	*get_sline(char *backup);
char	*ft_strchr(char *s, int c);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
char	*ft_strdup(char *s);
char	*get_rest(char *backup);

#endif
