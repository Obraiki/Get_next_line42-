/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obraiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:18:27 by obraiki           #+#    #+#             */
/*   Updated: 2021/11/24 11:56:33 by obraiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<sys/types.h>
#include<sys/stat.h>
#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return (&s[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	size_t	j;
	char	*str;

	if (s1 == NULL)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	len = ft_strlen (s1) + ft_strlen (s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	len = 0;
	while (s1[len])
	{
		str[len] = s1[len];
		len++;
	}
	j = 0;
	while (s2[j])
		str[len++] = s2[j++];
	str[len] = '\0';
	free(s1);
	s1 = NULL;
	return (str);
}
