/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obraiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:09:05 by obraiki           #+#    #+#             */
/*   Updated: 2021/11/25 11:55:02 by obraiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_read(char *s, int fd)
{
	char	*buf;
	int		n;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	n = 1;
	while (ft_strchr(s, '\n') == NULL && n != 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n == -1)
		{
			free (buf);
			return (NULL);
		}
		buf[n] = '\0';
		s = ft_strjoin(s, buf);
	}
	free(buf);
	return (s);
}

char	*ft_left(char *s)
{
	char	*len;
	size_t	i;
	size_t	j;

	i = 0;
	if (s[0] == '\0')
		return (NULL);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\n')
		i++;
	len = (char *)malloc(sizeof(char) * i + 1);
	if (len == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		len[j] = s[j];
		j++;
	}
	len[j] = '\0';
	return (len);
}

char	*ft_right(char *b)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	while (b[i] != '\n' && b[i] != '\0')
	i++;
	if (ft_strlen(b) == i)
	{
		free (b);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(b) - i + 1));
	j = 0;
	while (b[i++] != '\0')
	{
		str[j] = b[i];
		j++;
	}
	str[j] = '\0';
	free (b);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	line = ft_read(line, fd);
	if (line == NULL)
		return (NULL);
		buf = ft_left(line);
		line = ft_right(line);
	return (buf);
}
int main ()
{
int fd;	
char *c;
fd = open("fofo.txt", O_RDONLY);
 while ((c = get_next_line(fd)) != NULL)
 {
   printf("%s", c);
 }
 close(fd);
}
