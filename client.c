/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:32:20 by ricmanue          #+#    #+#             */
/*   Updated: 2024/12/02 12:04:45 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
