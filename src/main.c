/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoden <ncoden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 11:03:54 by ncoden            #+#    #+#             */
/*   Updated: 2015/04/22 18:32:08 by ncoden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
	#include <limits.h>
int			main(void)
{
	int			len;

	len = ft_printf("{%10R}");
	printf("\nlen = %d\n", len);
	len = printf("{%10R}");
	printf("\nlen = %d\n", len);
	return (0);
}
