/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:05:24 by jede-ara          #+#    #+#             */
/*   Updated: 2023/01/18 18:06:42 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	send_sig(int pid, char *str)
{
	int		bit;
	char	c;
	int		i;

	i = 0;
	bit = 0;
	while (str[i] != '\0')
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
			usleep(100);
		}
		i++;
		bit = 0;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
		return (ft_printf("client: invalid arguments \n"));
	pid = ft_atoi(av[1]);
	send_sig(pid, av[2]);
	return (0);
}
