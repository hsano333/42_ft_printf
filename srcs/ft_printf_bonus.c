/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:16:50 by hsano             #+#    #+#             */
/*   Updated: 2022/08/06 01:53:47 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "print.h"
#include "common.h"
#include "parse.h"

int	ft_printf(const char *str, ...)
{
	int		print_size;
	t_list	*c_list;
	va_list	args;

	c_list = parse_str(str);
	va_start(args, str);
	print_size = print(str, c_list, &args);
	return (print_size);
}