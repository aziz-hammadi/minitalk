/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammad <ahammad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 13:31:41 by ahammad           #+#    #+#             */
/*   Updated: 2021/10/27 13:41:50 by ahammad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

static void	char_to_bin(unsigned char c, int pid)
{
	unsigned int	bin;

	bin = 128;
	while (bin)
	{
		if (bin <= c)
		{
			c -= bin;
			kill(pid, SIGUSR2);
		}
		else
			kill(pid, SIGUSR1);
		bin /= 2;
		usleep(100);
	}
}

int	main(int argc, char	**argv)
{
	int		pid_server;
	int		i;

	i = 0;
	if (argc != 3)
	{
		printf("Error, Missing argument.");
		exit (EXIT_FAILURE);
	}
	pid_server = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		char_to_bin(argv[2][i], pid_server);
		usleep(100);
		i++;
	}
	exit (EXIT_SUCCESS);
}
