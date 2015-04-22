/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoden <ncoden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 16:14:13 by ncoden            #+#    #+#             */
/*   Updated: 2015/04/22 18:33:45 by ncoden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			arg_process(va_list *args, char **ptr)
{
	int			modifier;
	t_frmt		format;

	if (**ptr == '%')
	{
		(*ptr)++;
		if (**ptr != '\0')
		{
			*ptr = arg_parse(&format, &modifier, *ptr);
			return (arg_print(args, &format, modifier));
		}
	}
	return (0);
}

char			*arg_parse(t_frmt *format, int *modifier, char *ptr)
{
	ft_frmtoptsset(format, ft_prschrs(&ptr, "#0- +"));
	if (!(ft_prsnbr(&ptr, &(format->min_len))))
		format->min_len = -1;
	ft_prschr(&ptr, '.');
	if (!(ft_prsnbr(&ptr, &(format->precision))))
		format->precision = -1;
	if (ft_prsstr(&ptr, "ll"))
		*modifier = MDF_LL;
	else if (ft_prsstr(&ptr, "hh"))
		*modifier = MDF_HH;
	else if ((*modifier = ft_chrpos("hljz", *ptr)) != -1)
		ptr++;
	if ((format->format = ft_chrswitch("%sSpdDioOuUxXcC", *ptr)) != 0)
		ptr++;
	return (ptr);
}

size_t			arg_print(va_list *args, t_frmt *format, int modifier)
{
	char			c;

	c = format->format;
	if (c == '%')
		return (ft_frmtiputc('%', format));
	else if (c == 'c' || c == 'C')
		return (arg_print_chr(args, format, modifier));
	else if (c == 'd' || c == 'i')
		return (arg_print_int(args, format, modifier));
	else if ((ft_chrpos("ouxX", c)) != -1)
		return (arg_print_uint(args, format, modifier));
	else if ((ft_chrpos("DOU", c)) != -1)
		return (arg_print_lint(args, format));
	else if ((ft_chrpos("psS", c)) != -1)
		return (arg_print_ptr(args, format, modifier));
	else
		return (ft_frmtiputc(c, format));
	return (0);
}
