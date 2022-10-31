/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/15 14:47:07 by jbax          #+#    #+#                 */
/*   Updated: 2022/03/16 12:19:24 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	findc(int order, char *orders, char k, int *reurn);
static void	findi(int orderi, unsigned int orderd, int *reurn);
static void	findx(unsigned long long orderx, char cap, int findp, int *reurn);
static int	gifback(const char *order, va_list arg, int count, int *reurn);

int	ft_printf(const char *order, ...)
{
	va_list	arg;
	int		count;
	int		i;
	int		*reurn;

	va_start(arg, order);
	count = 0;
	i = count;
	reurn = &i;
	while (order[count] != '\0')
	{
		if (order[count] == '%' && order[count + 1] != '%')
			count += gifback(order, arg, count, reurn);
		else if (order[count] == '%' && order[count + 1] == '%')
			count += countwriting(reurn, &order[count], 1, 2);
		else
			count += countwriting(reurn, &order[count], 1, 1);
	}
	va_end(arg);
	return (*reurn);
}

static void	findc(int orderc, char *orders, char k, int *reurn)
{
	char	conver;
	int		i;

	i = 0;
	if (orders == NULL)
		countwriting(reurn, "(null)", 6, 1);
	if (k == 's' && orders != NULL)
	{
		while (orders[i] != '\0')
			i += countwriting(reurn, &orders[i], 1, 1);
	}
	conver = orderc;
	if (k == 'c')
		countwriting(reurn, &conver, 1, 2);
}

static void	findi(int orderi, unsigned int orderd, int *reurn)
{
	char			c;
	unsigned int	d;

	if (orderi < 0)
	{
		countwriting(reurn, "-", 1, 2);
		d = orderi * -1;
	}
	else if (orderd > 0)
		d = orderd;
	else
		d = orderi;
	c = d % 10 + '0';
	d = d / 10;
	if (d > 0)
		findi(0, d, reurn);
	countwriting(reurn, &c, 1, 0);
}

static void	findx(unsigned long long orderx, char cap, int findp, int *reurn)
{
	unsigned long long	d;
	char				c;
	int					i;

	if (findp < 1)
		countwriting(reurn, "0x", 2, 1);
	d = orderx;
	i = d % 16;
	d = d / 16;
	if (i > 9)
		c = i + cap - 33;
	else
		c = i + '0';
	if (d > 0)
		findx(d, cap, 1, reurn);
	countwriting(reurn, &c, 1, 2);
}

static int	gifback(const char *order, va_list arg, int count, int *reurn)
{
	if (order[count + 1] == 'c')
		findc(va_arg(arg, int), "0", 'c', reurn);
	else if (order[count + 1] == 's')
		findc(0, va_arg(arg, char *), 's', reurn);
	else if (order[count + 1] == 'i' || order[count + 1] == 'd')
		findi(va_arg(arg, int), 0, reurn);
	else if (order[count + 1] == 'u')
		findi(0, va_arg(arg, unsigned int), reurn);
	else if (order[count + 1] == 'x' || order[count + 1] == 'X')
		findx(va_arg(arg, unsigned int), order[count + 1], 1, reurn);
	else if (order[count + 1] == 'p')
		findx(va_arg(arg, unsigned long long), 'x', 0, reurn);
	else if (order[count + 1] == '\0')
		return (1);
	else
		countwriting(reurn, &order[count + 1], 1, 1);
	return (2);
}
