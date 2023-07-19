/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:28:49 by startagl          #+#    #+#             */
/*   Updated: 2023/03/17 10:09:19 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_print_bit(int signal, siginfo_t *info, void *context)
{
	static int	res;
	static int	bit;

	(void)context;
	if (signal == SIGUSR1)
		res |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (res == 0)
			kill(info->si_pid, SIGUSR2);
		ft_printf("%c", res);
		bit = 0;
		res = 0;
	}
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	act;

	(void)av;
	if (ac != 1)
	{
		ft_printf("Error\n");
		return (0);
	}
	pid = getpid();
	ft_printf("PID:\t%d\n", pid);
	act.sa_sigaction = ft_print_bit;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	while (1)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		pause();
	}
	return (0);
}
