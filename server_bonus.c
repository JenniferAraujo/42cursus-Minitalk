/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:27:43 by jede-ara          #+#    #+#             */
/*   Updated: 2023/01/19 16:50:16 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

unsigned char	*g_out = 0;

void	man_signal(int signal, siginfo_t *info, void *p)
{
	static int				i = 0;
	static unsigned char	binary;
	static unsigned char	bit;

	(void)p;
	binary = (signal == SIGUSR1);
	bit = bit | (binary << i);
	i++;
	if (i == 8)
	{
		g_out = ft_strjoincharacter(g_out, bit);
		if (bit == '\0')
		{
			ft_printf("%s", g_out);
			kill(info->si_pid, SIGUSR1);
			free (g_out);
			g_out = 0;
		}
		bit = 0;
		i = 0;
	}
}

void	ft_sig(void)
{
	struct sigaction	a;

	a.sa_sigaction = &man_signal;
	a.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &a, NULL);
	sigaction(SIGUSR2, &a, NULL);
}

int	main(void)
{
	ft_printf("Your pid is: %d\n", getpid());
	ft_sig();
	while (1)
		pause();
	return (0);
}
