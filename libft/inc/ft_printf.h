/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:17:29 by ricmanue          #+#    #+#             */
/*   Updated: 2025/01/08 14:04:32 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

int		ft_printf(const char *str, ...);
int		ft_print_char(char c);
int		ft_print_str(char *str);
int		ft_print_num(int n);
int		ft_print_unsi(unsigned int n);
int		ft_print_ptr(void *n);
int		ft_print_hex(unsigned int n, char specifier);
int		ft_base_size(long unsigned int n, int base_len);
char	*ft_itoa_base(long unsigned int n, int base_len, char *base);

#endif
