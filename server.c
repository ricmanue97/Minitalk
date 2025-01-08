/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue < ricmanue@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:32:28 by ricmanue          #+#    #+#             */
/*   Updated: 2025/01/08 09:19:37 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_bintoa(int signal, char *c)
{
	if(signal == SIGUSR1)
		*c = (*c << 1) | 1;
	else if(signal == SIGUSR2)
		*c <<= 1;
}
void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static char	c;
	static int	bit_count;
	static int	pid;

	(void)context;
	if (pid != 0 && pid != info->si_pid)
		return ;
	if (pid == 0)
		pid = info->si_pid;
	ft_bintoa(signal, &c);

	if (++bit_count == 8)
	{
		bit_count = 0;
		if(c == '\0')
		{
			kill(pid, SIGUSR1);
			pid = 0;
			return ;
		}
		write(1, &c, 1);
		c = 0;
	}
	kill(pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	signal;

	ft_printf("Ricmanue's server:\n server PID is %d\n", getpid());
	sigemptyset(&signal.sa_mask);
	signal.sa_flags = SA_SIGINFO;
	signal.sa_sigaction = signal_handler;
	
	if (sigaction(SIGUSR1, &signal, NULL) == -1 || 
		sigaction(SIGUSR2, &signal, NULL) == -1)
		return(ft_putstr_fd("ERROR\n" , 1), 1);
	while (1)
		pause();
	return (0);
}
