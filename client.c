/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:32:20 by ricmanue          #+#    #+#             */
/*   Updated: 2024/12/03 13:48:20 by ricmanue         ###   ########.fr       */
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
	if (ac == 3)
	{
		int		pid;
		char	*message;

		pid = ft_atoi(av[1]);
		if (!pid)
		{
			ft_printf("PID error");
			return (0);
		}
		message = av[2];
		if (message[0] == "\0")
		{
			printf("No message sent");
			return (0);
		}
		else
		{
			if (ac < 3)
				ft_printf("Too litlle arguments, need PID and message\n");
			else if (ac > 3)
				ft_printf("Too many arguments, need PID and message\n");
		}
	}
}
