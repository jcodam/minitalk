/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/24 14:20:16 by jbax          #+#    #+#                 */
/*   Updated: 2022/10/17 16:13:01 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

int	ft_printf(const char *order, ...);
int	countwriting(int *howlong, const char *prin, int charcount, int plussen);

#endif