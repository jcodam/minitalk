/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 14:45:02 by jbax          #+#    #+#                 */
/*   Updated: 2022/10/28 18:56:21 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

static int	bit_shift(char base, int calc_num)
{
	return ((base >> calc_num) & 1);
}

int main(int argc, char const *argv[])
{
	int id;
	int i;
	int j;
	int child = fork();
	// signal(SIGUSR1)
	if (child == 0)
	{
		sleep(1);
		ft_printf("\n------took to long---------\n");
		sleep(100);
	}
	if (argc != 3)
	{
		ft_putstr_fd("Error\nhave not resiefd 2 arguments\n", 2);
		exit(2);
	}
	i = 0;
	j = 0;
	id = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		// ft_printf("char-%c-int-%d\n", argv[2][i], argv[2][i]);
		while (j < 8)
		{
			if (bit_shift(argv[2][i], j))
				kill(id, SIGUSR1);
			else
				kill(id, SIGUSR2);
			j++;
			usleep(100);
		}
		j = 0;
		i++;
		usleep(50);
	}
	sleep(2);
	kill(child, SIGINT);
	ft_printf("\nDONE?\n");
	return (0);
}
