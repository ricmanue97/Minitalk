/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:55:58 by ricmanue          #+#    #+#             */
/*   Updated: 2025/01/08 14:05:23 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/get_next_line.h"

static size_t	ft_gnl_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] && str[len] != '\n' )
		len++;
	if (str[len] == '\n')
		len++;
	return (len);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	size_t	totallen;
	size_t	len1;
	size_t	len2;
	char	*str;

	len1 = 0;
	len2 = -1;
	totallen = ft_gnl_strlen(s1) + ft_gnl_strlen(s2);
	str = malloc(sizeof(char) * totallen + 1);
	if (!str)
		return (NULL);
	while (s1 && s1[len1])
	{
		str[len1] = s1[len1];
		len1++;
	}
	while (s2[++len2])
	{
		str[len1++] = s2[len2];
		if (s2[len2] == '\n')
			break ;
	}
	str[len1] = '\0';
	free (s1);
	return (str);
}
