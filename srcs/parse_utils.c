/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 15:25:55 by hsano             #+#    #+#             */
/*   Updated: 2022/08/05 14:59:41 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	clear_conversion(t_conversion *node)
{
	free(node);
}

int	is_invalid_int_numbers(const char **str, size_t size, int mode)
{
	size_t	i;
	size_t	first_digit;

	if (mode == FRONT)
	{
		i = 0;
		while (!('1' <= (*str)[i] && (*str)[i] <= '9') && i < size)
			i++;
		first_digit = i;
		while (('0' <= (*str)[i] && (*str)[i] <= '9') && i < size)
			i++;
		if (i - first_digit >= 11)
			return (true);
	}
	else
	{
		i = size - 1;
		while (('0' <= (*str)[i] && (*str)[i] <= '9') && i > 0)
			i--;
		if (size - i >= 11)
			return (true);
		first_digit = ++i;
	}
	*str = &((*str)[first_digit]);
	return (false);
}

int	ft_atoin(const char *str, size_t size, int mode, int *error)
{
	char	*p;
	int		tmp_int;
	int		tmp_error;

	tmp_error = is_invalid_int_numbers(&str, size, mode);
	if (tmp_error)
	{
		*error = true;
		return (-2);
	}
	p = ft_substr(str, 0, size);
	if (!p)
	{
		*error = true;
		return (-2);
	}
	tmp_int = ft_atoi_base(p, BASE_DIGIT, error);
	free(p);
	if (*error)
		return (-2);
	return (tmp_int);
}

int	exist_char(const char *str, char c, size_t size)
{
	if (ft_memchr(str, c, size))
		return (true);
	return (false);
}

//
void	info_conversion(t_conversion *convs)
{
	printf("\ninfo:convs->point:[%s]", convs->point);
	printf("convs->size:%zu\n", convs->size);
	printf("convs->conversion:%c\n", convs->conversion);
	printf("convs->mini_width:%d\n", convs->mini_width);
	printf("convs->precision:%d\n", convs->precision);
	printf("convs->flag_minus:%d\n", convs->flag_minus);
	printf("convs->flag_plus:%d\n", convs->flag_plus);
	printf("convs->flag_sharp:%d\n", convs->flag_sharp);
	printf("convs->flag_space:%d\n", convs->flag_space);
	printf("convs->flag_zero:%d\n", convs->flag_zero);
	printf("convs->valid:%d\n", convs->valid);
	printf("convs->mem_err:%d\n", convs->mem_err);
	printf("convs->minus_value:%d\n", convs->minus_value);
	printf("convs->print_size:%zu\n", convs->print_size);
}
//
