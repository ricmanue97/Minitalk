/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:24:41 by ricmanue          #+#    #+#             */
/*   Updated: 2024/05/07 14:34:57 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

//Copies n bytes from memory area src to memory area dest.
// The memory areas may overlap.
//Returns a pointer to dest.

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*sorce;

	dst = (unsigned char *) dest;
	sorce = (unsigned char *) src;
	if (src == NULL && dest == NULL)
		return (dest);
	if (dst > sorce)
	{
		while (n > 0)
		{
			n--;
			*(dst + n) = *(sorce + n);
		}
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (dest);
}
