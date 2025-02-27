/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:48:35 by ricmanue          #+#    #+#             */
/*   Updated: 2025/01/08 14:05:23 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_base_size(long unsigned int n, int base_len)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / base_len;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(long unsigned int n, int base_len, char *base)
{
	char	*str;
	int		len;

	len = ft_base_size(n, base_len);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = 48;
	while (n)
	{
		str[len - 1] = base[n % base_len];
		n = n / base_len;
		len--;
	}
	return (str);
}
