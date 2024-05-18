/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:20:28 by marsoare          #+#    #+#             */
/*   Updated: 2024/05/17 18:10:28 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*endstr;
	int		totlen;
	int		i;

	totlen = ft_strlen(s1) + ft_strlen(s2);
	endstr = (char *)malloc(sizeof(char) * totlen + 1);
	if (endstr == 0)
		return (NULL);
	i = 0;
	while (*s1)
	{
		endstr[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		endstr[i] = *s2;
		i++;
		s2++;
	}
	endstr[i] = 0;
	return (endstr);
}

int	ft_strlen(const char *s)
{
	int	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == *s)
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	dup = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	char	*str;
	int		n;

	n = size * nmemb;
	p = malloc(n);
	str = (char *) p;
	if (str)
	{
		while (n > 0)
		{
			str[n - 1] = 0;
			n--;
		}
	}
	return (str);
}