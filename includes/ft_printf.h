/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoden <ncoden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 10:59:54 by ncoden            #+#    #+#             */
/*   Updated: 2015/04/28 10:23:31 by ncoden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
	#include <stdio.h>

# include "libft.h"

# define MDF_H 0
# define MDF_L 1
# define MDF_J 2
# define MDF_Z 3

# define MDF_HH 10
# define MDF_LL 11

int			ft_printf(const char *format, ...);
size_t		analyse(va_list *args, const char *format);

size_t		arg_process(va_list *args, char **ptr);

char		*arg_parse(va_list *args, t_frmt *format, int *modifier,
				char *ptr);
int			arg_parse_wildchar(va_list *args, int *dst, char **ptr);

size_t		arg_print(va_list *args, t_frmt *format, int modifier);
size_t		arg_print_int(va_list *args, t_frmt *format, int modifier);
size_t		arg_print_uint(va_list *args, t_frmt *format, int modifier);
size_t		arg_print_lint(va_list *args, t_frmt *format);
size_t		arg_print_ptr(va_list *args, t_frmt *format, int modifier);
size_t		arg_print_chr(va_list *args, t_frmt *format, int modifier);

#endif
