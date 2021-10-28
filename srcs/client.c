/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammad <ahammad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 13:31:41 by ahammad           #+#    #+#             */
/*   Updated: 2021/10/28 22:14:52 by ahammad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	check_argc(int argc)
{
	if (argc == 1)
	{
		printf("Missing ""PID"" ""Message""");
		exit (1);
	}
	if (argc == 2)
	{
		printf("Missing ""Message""");
		exit (1);
	}
	if (argc > 3)
	{
		printf("Missing ""client.out"" ""PID"" ""Message""");
		exit (1);
	}
}

static void	convert_to_binary(unsigned char c, int pid)
{
	unsigned int	binary;

	binary = 128;
	while (binary)
	{
		if (binary <= c)
		{
			c = c - binary;
			kill(pid, SIGUSR1);
		}
		else
			kill(pid, SIGUSR2);
		binary = binary / 2;
		usleep(100);
	}
}

int	main(int argc, char	**argv)
{
	int		pid_server;
	int		i;

	i = 0;
	check_argc(argc);
	pid_server = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		convert_to_binary(argv[2][i], pid_server);
		usleep(100);
		i++;
	}
	exit (0);
}
