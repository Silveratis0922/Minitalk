/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:11:41 by tchantro          #+#    #+#             */
/*   Updated: 2022/11/03 13:52:24 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	end_of_file(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(pid, SIGUSR2);
		usleep(2000);
		i++;
	}
}

void	test(char *str, int pid)
{
	int	c;
	int	i;

	i = 0;
	while (str[i])
	{
		c = 128;
		while (c >= 1)
		{
			if (str[i] >= c)
			{
				kill(pid, SIGUSR1);
				str[i] = str[i] - c;
			}
			else
				kill(pid, SIGUSR2);
			c = c / 2;
			usleep(2000);
		}
		i++;
	}
}

int	verif_pid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		if (verif_pid(argv[1]) != 0)
			return (write(2, "Invalid PID argument.\n", 22));
		pid = ft_atoi(argv[1]);
		if (pid < 0)
			return (write(2, "Invalid PID argument.\n", 22));
		test(argv[2], pid);
		end_of_file(pid);
	}
	else if (argc < 3)
		return (write(2, "Arguments is missing.\n", 22));
	else
		return (write(2, "Too many arguments.\n", 20));
	return (0);
}
