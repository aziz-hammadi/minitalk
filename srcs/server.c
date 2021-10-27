/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammad <ahammad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 13:32:28 by ahammad           #+#    #+#             */
/*   Updated: 2021/10/27 13:41:41 by ahammad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

static void	build_the_char(int sig)
{
	static int	bin;
	static int	result;
	static int	power;
	char		c;

	if (power == 0)
		bin = 128;
	if (sig == SIGUSR2)
		result += bin;
	bin /= 2;
	power++;
	if (power == 8)
	{
		c = result;
		write(1, &c, 1);
		power = 0;
		bin = 128;
		result = 0;
	}
}

int	main(void)
{
	printf("The PID is : %d\n", getpid());
	signal(SIGUSR1, build_the_char);
	signal(SIGUSR2, build_the_char);
	while (1)
		pause();
}
