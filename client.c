/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:32:20 by ricmanue          #+#    #+#             */
/*   Updated: 2024/12/03 15:43:33 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_signal;

void signal_handler(int sig_nbr)
{
	static int	bits;

	g_signal = true;
	if (sig_nbr == SIGUSR1)
		bits++;
	else if (sig_nbr == SIGUSR2)
		ft_printf("This message was ->%d bytes", bits / 8);
}

int	ft_ascii_to_bin(char letter, int pid)
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
	struct sigaction	sa;
	int					pid;

	if (ac != 3)
	{
			if (ac < 3)
				ft_printf("Too litlle arguments, need PID and message\n");
			else if (ac > 3)
				ft_printf("Too many arguments, need PID and message\n");
	}
	pid = ft_atoi(av[1]);
	if (!pid || kill(pid,0) == -1)
		return(ft_printf("PID error"));
	ft_bzero(&sa, sizeof((struct sigaction)));
	sa.sa_flags = SA_SIGINFO;
	sa.sa_handler = signal_handler;



}
