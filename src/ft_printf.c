/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoden <ncoden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 10:58:38 by ncoden            #+#    #+#             */
/*   Updated: 2015/04/28 10:23:38 by ncoden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ft_printf(const char *format, ...)
{
	size_t		len;
	va_list		args;

	len = 0;
	if (format)
	{
		va_start(args, format);
		len = analyse(&args, format);
		va_end(args);
	}
	return (len);
}

inline size_t			analyse(va_list *args, const char *format)
{
	size_t		len;
	char		*ptr;
	char		*start;

	len = 0;
	ptr = (char *)format;
	start = (char *)format;
	while (*ptr != '\0')
	{
		if (*ptr == '%')
		{
			ft_putnstr(start, ptr - start);
			len += arg_process(args, &ptr);
			start = ptr;
		}
		else if (*ptr != '\0')
		{
			len++;
			ptr++;
		}
	}
	ft_putnstr(start, ptr - start);
	return (len);
}
