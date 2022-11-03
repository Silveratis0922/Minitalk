/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:12:07 by tchantro          #+#    #+#             */
/*   Updated: 2022/11/03 13:53:55 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void	string_send(char *c)
{
	static char	*str;

	if (c[0] == 0)
	{
		ft_putstr_fd(str, 1);
		ft_putchar_fd('\n', 1);
		free(str);
		str = NULL;
	}
	else if (str == NULL)
		str = ft_strdup(c);
	else if (str != NULL)
		str = ft_strjoin(str, c);
}

void	get_char(int *tab)
{
	int		i;
	int		bin;
	int		res;
	char	c[2];

	i = 0;
	bin = 128;
	res = 0;
	while (i <= 7)
	{
		if (tab[i] == 1)
			res = res + bin;
		bin = bin / 2;
		i++;
	}
	c[0] = res;
	c[1] = '\0';
	string_send(c);
}

void	handler(int signal)
{
	static int	i = 0;
	static int	tab[8];	

	if (signal == SIGUSR1)
		tab[i] = 1;
	else
		tab[i] = 0;
	i++;
	if (i == 8)
	{
		get_char(tab);
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void) argv;
	if (argc == 1)
	{
		ft_printf("%d\n", getpid());
		sa.sa_handler = handler;
		sigemptyset(&sa.sa_mask);
		sigaction(SIGUSR1, &sa, 0);
		sigaction(SIGUSR2, &sa, 0);
		while (1)
			pause();
	}
	else
		return (write(2, "Too many arguments.\n", 20));
	return (0);
}
