/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 14:45:02 by jbax          #+#    #+#                 */
/*   Updated: 2022/11/04 13:47:38 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

int	g_stop = 1;
// int	g_child = 0;

static void	send_end(int id)
{
	int	j;

	j = 8;
	while (j)
	{
		while (g_stop)
		{
		}
		g_stop = 1;
		j--;
		kill(id, SIGUSR1);
	}
}

static void	send_bits(int id, char const *str)
{
	int	i[2];

	if (g_stop)
		ft_putstr_fd("can't recive signial\ncheck the server id\n", 2);
	if (g_stop)
		exit(1);
	i[0] = 0;
	while (str[i[0]])
	{
		i[1] = 8;
		while (i[1])
		{
			while (g_stop)
			{
			}
			g_stop = 1;
			i[1]--;
			if ((str[i[0]] >> i[1]) & 1)
				kill(id, SIGUSR2);
			else
				kill(id, SIGUSR1);
		}
		i[0]++;
	}
	send_end(id);
}

static int	send_id(int id)
{
	int	i;
	int	my_id;

	my_id = getpid();
	i = 32;
	while (i)
	{
		i--;
		if ((my_id >> i) & 1)
			kill(id, SIGUSR2);
		else
			kill(id, SIGUSR1);
		usleep(50);
	}
	return (1);
}

static void	sighandler(int signum)
{
	if (signum == SIGUSR1)
	{
		g_stop = 0;
	}
	if (signum == SIGUSR2)
	{
		ft_printf("string was send\nclosing client\n");
		exit(1);
	}
}
		// system("leaks -q client");
		// system("leaks -q server");

int	main(int argc, char const *argv[])
{
	int					id;
	struct sigaction	sa;

	sa.sa_flags = SA_RESTART;
	sa.__sigaction_u.__sa_handler = &sighandler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (argc != 3)
	{
		ft_putstr_fd("Error\nhave received more or les than 2 arguments\n", 2);
		exit(2);
	}
	id = ft_atoi(argv[1]);
	send_id(id);
	send_bits(id, argv[2]);
	sleep(20);
	return (0);
}
