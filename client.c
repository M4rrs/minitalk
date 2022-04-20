/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:29:02 by nnorazma          #+#    #+#             */
/*   Updated: 2022/04/20 17:29:03 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_binary(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++ ;
		usleep(42);
	}
}

static void	send_message(int pid, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		send_binary(pid, str[i]);
	send_binary(pid, 0);
}

static void	response(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_putstr_fd("Message received.\n", 1);
	}
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	char				*str;
	struct sigaction	sa;

	if (argc == 2)
	{
		ft_putstr_fd("No message entered.\n", 1);
		exit(EXIT_FAILURE);
	}
	else if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		ft_putstr_fd("Sent: ", 1);
		ft_putnbr_fd(ft_strlen(str), 1);
		ft_putchar_fd('\n', 1);
		sa.sa_handler = response;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		send_message(pid, str);
	}
	return (0);
}
