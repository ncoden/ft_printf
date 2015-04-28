/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoden <ncoden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 16:14:13 by ncoden            #+#    #+#             */
/*   Updated: 2015/04/28 13:20:55 by ncoden           ###   ########.fr       */
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
			*ptr = arg_parse(args, &format, &modifier, *ptr);
			return (arg_print(args, &format, modifier));
		}
	}
	return (0);
}

char			*arg_parse(va_list *args, t_frmt *format, int *modifier,
					char *ptr)
{
	ft_frmtoptsset(format, ft_prschrs(&ptr, "#0- +"));
	arg_parse_wildchar(args, &(format->min_len), &ptr);
	if (format->min_len < 0)
	{
		format->min_len = -(format->min_len);
		format->opt_minus = 1;
	}
	if (ft_prschr(&ptr, '.'))
		arg_parse_wildchar(args, &(format->precision), &ptr);
	else
		format->precision = -1;
	if (ft_prsstr(&ptr, "ll"))
		*modifier = MDF_LL;
	else if (ft_prsstr(&ptr, "hh"))
		*modifier = MDF_HH;
	else if ((*modifier = ft_chrpos("hljzL", *ptr)) != -1)
		ptr++;
	format->format = *ptr;
	if (*ptr != '\0')
		ptr++;
	return (ptr);
}

int				arg_parse_wildchar(va_list *args, int *dst, char **ptr)
{
	int			res;

	if (**ptr == '*')
	{
		*dst = va_arg(*args, int);
		(*ptr)++;
	}
	else if (!(ft_prsnbr(ptr, dst)))
		return (0);
	if ((arg_parse_wildchar(args, &res, ptr)))
		*dst = res;
	return (1);
}

size_t			arg_print(va_list *args, t_frmt *format, int modifier)
{
	char			c;

	c = format->format;
	if (c == '%')
		return (ft_frmtputc('%', format));
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
		return (ft_frmtputc(c, format));
	return (0);
}
