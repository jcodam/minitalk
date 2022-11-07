/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 14:45:20 by jbax          #+#    #+#                 */
/*   Updated: 2022/11/04 13:10:03 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

int	g_bits32 = 0;

static int	make_char(int bit)
{
	static char	c = 0;
	static int	i = 0;

	if (i == 8)
		i = 0;
	c = (c << 1) | bit;
	i++;
	if (i == 8)
		write(1, &c, 1);
	if (i == 8 && !c)
	{
		g_bits32 = 0;
		return (1);
	}
	return (0);
}

static void	sighandler(int signum)
{
	static int	client_id;
	int			sig_change;

	if (g_bits32 < 32)
	{
		client_id = (client_id << 1) | (signum - 30);
		g_bits32++;
		if (g_bits32 == 32)
			kill(client_id, SIGUSR1);
	}
	else
	{
		if (signum == SIGUSR1 && g_bits32 == 32)
			sig_change = make_char(0);
		if (signum == SIGUSR2 && g_bits32 == 32)
			sig_change = make_char(1);
		if (signum == SIGINT)
			exit(1);
		kill(client_id, SIGUSR1 + sig_change);
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					id;

	id = getpid();
	ft_printf("id--%d\n", id);
	sa.sa_flags = SA_RESTART;
	sa.__sigaction_u.__sa_handler = &sighandler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
