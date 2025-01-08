/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:32:20 by ricmanue          #+#    #+#             */
/*   Updated: 2025/01/08 14:39:00 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_signal;

void signal_handler(int sig_nbr)
{
	static int	bits;

	g_signal = true;
	if (sig_nbr == SIGUSR2)
		bits++;
	else if (sig_nbr == SIGUSR1)
		ft_printf("This message was ->%d bytes\n", bits / 8);
}

int	ft_atobin(char letter, int pid)
{
	int	i;
	int	bin;

	bin = 7;
	while (bin >= 0)
	{
		i = 0;
		if((letter >> bin) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_signal == false)
		{
			if (i == 10)
			{
				ft_putstr_fd("Server not responding\n", 2);
				exit(0);
			}
			i++;
			usleep(1000000);
		}
		g_signal = false;
		bin--;
	}
	return (0);
}

int	main(int ac, char **av)
{
	struct sigaction	signal;
	int					pid;
	int					i;

	i = 0;
	if (ac > 3)
		ft_printf("Too many arguments, need PID and message\n");
	if (ac < 3)
		ft_printf("Too litlle arguments, need PID and message\n");
	pid = ft_atoi(av[1]);
	if (!pid || kill(pid,0) == -1)
		return(ft_printf("PID error"));
	ft_bzero(&signal, sizeof(struct sigaction));
	signal.sa_flags = SA_SIGINFO;
	signal.sa_handler = signal_handler;
	if (pid < 0 || kill(pid, 0) == -1)
		return (ft_printf("PID error \n"));
	if (sigaction(SIGUSR1, &signal, NULL) == -1 \
		|| sigaction(SIGUSR2, &signal, NULL) == -1)
		return (ft_putstr_fd("Error sigaction\n",2), 1);
	while (av[2][i])
		ft_atobin((av[2][i++]), pid);
	ft_atobin('\0', pid);
	return(0);
}
