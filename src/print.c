/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoden <ncoden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:57:22 by ncoden            #+#    #+#             */
/*   Updated: 2015/04/22 18:06:34 by ncoden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			arg_print_int(va_list *args, t_frmt *format, int modifier)
{
	long long int	nbr;

	if (modifier == MDF_HH)
		nbr = (signed char)va_arg(*args, long long int);
	else if (modifier == MDF_H)
		nbr = (short)va_arg(*args, long long int);
	else if (modifier == MDF_L)
		nbr = (long)va_arg(*args, long long int);
	else if (modifier == MDF_LL)
		nbr = (long long)va_arg(*args, long long int);
	else if (modifier == MDF_J)
		nbr = (intmax_t)va_arg(*args, long long int);
	else if (modifier == MDF_Z)
		nbr = (size_t)va_arg(*args, long long int);
	else
		nbr = (int)va_arg(*args, long long int);
	return (ft_frmtiput((void *)&nbr, format));
}

size_t			arg_print_uint(va_list *args, t_frmt *format, int modifier)
{
	unsigned long long int	nbr;

	if (modifier == MDF_HH)
		nbr = (unsigned char)va_arg(*args, unsigned long long int);
	else if (modifier == MDF_H)
		nbr = (unsigned short)va_arg(*args, unsigned long long int);
	else if (modifier == MDF_L)
		nbr = (unsigned long)va_arg(*args, unsigned long long int);
	else if (modifier == MDF_LL)
		nbr = (unsigned long long)va_arg(*args, unsigned long long int);
	else if (modifier == MDF_J)
		nbr = (uintmax_t)va_arg(*args, unsigned long long int);
	else if (modifier == MDF_Z)
		nbr = (size_t)va_arg(*args, unsigned long long int);
	else
		nbr = (unsigned int)va_arg(*args, long long int);
	return (ft_frmtiput((void *)&nbr, format));
}

size_t			arg_print_lint(va_list *args, t_frmt *format)
{
	long int	nbr;

	nbr = va_arg(*args, long int);
	return (ft_frmtiput((void *)&nbr, format));
}

size_t			arg_print_ptr(va_list *args, t_frmt *format, int modifier)
{
	void		*ptr;

	if (format->format == 's' && modifier == MDF_L)
		format->format = 'S';
	ptr = va_arg(*args, void *);
	return (ft_frmtiput(ptr, format));
}

size_t			arg_print_chr(va_list *args, t_frmt *format, int modifier)
{
	wint_t		c;

	if (format->format == 'c' && modifier == MDF_L)
		format->format = 'C';
	if (format->format == 'c')
		c = (wchar_t)va_arg(*args, wint_t);
	else
		c = (char)va_arg(*args, int);
	return (ft_frmtiput((void *)&c, format));
}
