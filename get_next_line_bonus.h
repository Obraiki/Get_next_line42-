/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obraiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:20:28 by obraiki           #+#    #+#             */
/*   Updated: 2021/11/25 10:54:56 by obraiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include<stdlib.h>
# include<stdio.h>
# include<fcntl.h>
# include<unistd.h>
# include "get_next_line.h"

size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*get_next_line(int fd);
#endif
