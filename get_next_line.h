/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnafiai <bnafiai@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:18:08 by bnafiai           #+#    #+#             */
/*   Updated: 2024/11/29 19:06:24 by bnafiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*my_strchar(char *str, int c);
size_t	my_strlen(char *s);
char	*my_strjoin(char *s1, char *s2);
char	*my_strdup(char *s);
#endif
