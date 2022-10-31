/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 14:45:20 by jbax          #+#    #+#                 */
/*   Updated: 2022/10/31 14:25:50 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

int x = 0;

static char bit_construct(char base, int bit, int num)
{
	return ((bit << num) | base);
}

// static int	bit_shift(char base, int calc_num)
// {
// 	return ((base >> calc_num) & 1);
// }

static void make_char(int bit)
{
	static char	c = 0;
	static int	i = 0;

	if (i == 8)
		c = 0;
	if (i == 8)
		i = 0;
	c = bit_construct(c, bit, i);
	i++;
	// ft_printf("char-%c-int-%d-num-%d-bit%d\n", c, c, i, bit);
	if (i == 8)
		write(1, &c, 1);
}

static void	sighandler(int signum)
{
	if (signum == SIGUSR1)
		make_char(1);
	if (signum == SIGUSR2)
		make_char(0);
	if (signum == SIGINT)
		exit(1);
}
// void sighandler1(int signum)
// {
// 	if (signum == SIGUSR1)
// 		x++;
// }

int	main(void)
{
	struct sigaction sa;
	int id = getpid();
	ft_printf("test--%d\n", id);
	sa.sa_flags = SA_RESTART;
	sa.__sigaction_u.__sa_handler = &sighandler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	// signal(SIGUSR1, sigchar);
	// signal(SIGUSR2, sighandler2);
	// SIGUSR1 = 'g';
	// id = getpid();
	// kill(id, SIGUSR1);
	while (1)
	{
		// pause();
		// ft_printf("test%d\n", x);
		// sleep(2);
	}
	return (0);
}
