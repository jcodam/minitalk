/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_extra.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/10 14:41:01 by jbax          #+#    #+#                 */
/*   Updated: 2022/03/16 12:41:13 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	countwriting(int *howlong, const char *prin, int charcount, int plussen)
{
	*howlong += write(1, prin, charcount);
	return (plussen);
}
