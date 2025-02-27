/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:36:07 by ricmanue          #+#    #+#             */
/*   Updated: 2024/05/08 18:55:12 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

// Allocates size len and returns a pointer to the allocated  memory.
// The memory is not initialized.
// Return a pointer to  the  allocated memory.
// On error, return NULL.

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	len;
	void	*arr;

	len = nmemb * size;
	if (size && (len / size) != nmemb)
		return (NULL);
	arr = malloc(len);
	if (!arr)
		return (NULL);
	ft_bzero(arr, len);
	return (arr);
}
