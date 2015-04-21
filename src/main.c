/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoden <ncoden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 11:03:54 by ncoden            #+#    #+#             */
/*   Updated: 2015/04/07 16:23:15 by ncoden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			main(void)
{
	int			len;

	len = ft_printf("---%12c---\n", 'D');
	printf("len = %d\n", len);
	len = printf("---%12c---\n", 'D');
	printf("len = %d\n", len);
	printf("size = %lu\n", sizeof(wchar_t));
	printf("size = %lu\n", sizeof(wint_t));
	printf("size = %lu\n", sizeof(size_t));
	return (0);
}
