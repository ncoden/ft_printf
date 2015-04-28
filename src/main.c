/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoden <ncoden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 11:03:54 by ncoden            #+#    #+#             */
/*   Updated: 2015/04/28 10:33:16 by ncoden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
	#include <locale.h>

int			main(void)
{
	int			len;

	ft_setunicode(UNI_UTF8);

	len = ft_printf("{%f}{%F}", 1.42, 1.42);
	printf("\nlen = %d\n", len);
	len = printf("{%f}{%F}", 1.42, 1.42);
	printf("\nlen = %d\n", len);
	return (0);
}
