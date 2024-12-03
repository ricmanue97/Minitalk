/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:32:28 by ricmanue          #+#    #+#             */
/*   Updated: 2024/12/03 13:48:12 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"



int	main(void)
{
	struct sigaction	signal;

	ft_printf("Ricmanue's server:\n server PID is %d\n", getpid());
	signal.sa_handler = signal_handler;

}
