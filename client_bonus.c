/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:27:47 by jede-ara          #+#    #+#             */
/*   Updated: 2023/01/19 16:35:43 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	send_sig(int pid, char *str)
{
	int		bit;
	char	c;
	int		i;
	int		len;

	i = 0;
	bit = 0;
	len = ft_strlen(str);
	while (i <= len)
	{
		c = str[i];
		while (bit < 8)
		{
			if (c & 0b00000001)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			c >>= 1;
			bit++;
			usleep(160);
		}
		i++;
		bit = 0;
	}
}

void	man_signal(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Message received\n");
}

void	ft_sig(void)
{
	struct sigaction	a;

	a.sa_handler = &man_signal;
	a.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &a, NULL);
	sigaction(SIGUSR2, &a, NULL);
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
		return (ft_printf("client: invalid arguments \n"));
	pid = ft_atoi(av[1]);
	ft_sig();
	send_sig(pid, av[2]);
	return (0);
}
