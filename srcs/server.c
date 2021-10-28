/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammad <ahammad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 13:32:28 by ahammad           #+#    #+#             */
/*   Updated: 2021/10/28 22:15:29 by ahammad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	build_the_char(int sig)
{
	char		c;
	static int	binary;
	static int	result;
	static int	power;

	if (power == 0)
		binary = 128;
	if (sig == SIGUSR1)
		result = result + binary;
	binary = binary / 2;
	power++;
	if (power == 8)
	{
		c = result;
		ft_putchar(c);
		power = 0;
		binary = 128;
		result = 0;
	}
}

int	main(void)
{
	signal(SIGUSR2, build_the_char);
	signal(SIGUSR1, build_the_char);
	printf("PID_SERVER : %d\n", getpid());
	while (1)
		pause();
	return (0);
}
