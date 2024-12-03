/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue < ricmanue@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:32:28 by ricmanue          #+#    #+#             */
/*   Updated: 2024/12/02 16:29:17 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void signal_handler(int sig_nbr)
{
	static int	count;
	static
}



int	main(void)
{
	struct sigaction	signal;
	
	ft_printf("Ricmanue's server:\n server PID is %d\n", getpid());
	signal.sa_handler = signal_handler;
	
}