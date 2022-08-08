/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:11:22 by hsano             #+#    #+#             */
/*   Updated: 2022/08/09 00:11:56 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

size_t	put_flag_minus(t_conversion *convs, char *str, int padding_len,
		char padding)
{
	size_t	print_size;

	print_size = 0;
	if (convs->minus_value)
		print_size += write(1, "-", 1);
	else if (convs->flag_plus && ft_isdigit(str[0]))
		print_size += write(1, "+", 1);
	else if (convs->flag_space && ft_isdigit(str[0]))
		print_size += write(1, " ", 1);
	print_size += write(1, str, convs->arg_len);
	while (padding_len--)
		print_size += write(1, &padding, 1);
	return (print_size);
}

size_t	put_except_minus(t_conversion *convs, char *str, int padding_len,
		char padding)
{
	size_t	print_size;

	print_size = 0;
	while (padding == ' ' && padding_len--)
		print_size += write(1, &padding, 1);
	if (convs->minus_value)
		print_size += write(1, "-", 1);
	else if (convs->flag_plus && ft_isdigit(str[0]))
		print_size += write(1, "+", 1);
	else if (convs->flag_space && ft_isdigit(str[0]))
		print_size += write(1, " ", 1);
	while (padding == '0' && padding_len--)
		print_size += write(1, &padding, 1);
	print_size += write(1, str, convs->arg_len);
	return (print_size);
}

int	get_padding_len(t_conversion *convs, char *str, int str_len)
{
	int		len;
	char	c;

	c = convs->conversion;
	len = str_len;
	if (convs->minus_value)
		len++;
	else if ((convs->flag_plus || convs->flag_space) && ft_isdigit(str[0]))
		len++;
	if (c == 's')
	{
		if (convs->mini_width > str_len && convs->mini_width >= 0)
			len = convs->mini_width - str_len;
		else
			len = 0;
	}
	else if (c == 'c' && convs->mini_width >= 0)
		len = convs->mini_width - 1;
	else if (convs->mini_width > len && convs->mini_width > 0)
		len = convs->mini_width - len;
	else
		len = 0;
	return (len);
}

size_t	ft_putstr_fd_wrapper(char *str, int fd, int *print_size)
{
	size_t	len;
	if (!str)
		return (0);
	len = ft_strlen(str);
	ft_putstr_fd(str, fd);
	if (*print_size == PRINT_SIZE_OVER || len > INT_MAX || *print_size > INT_MAX - (int)len)
		*print_size = PRINT_SIZE_OVER;
	else
		*print_size += len;
	return (len);
}
