/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 15:25:55 by hsano             #+#    #+#             */
/*   Updated: 2022/08/06 11:22:07 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "parse.h"

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

	if (size == 0 && mode == BACK)
		return (-1);
	else if (size == 1 && mode == BACK)
		return (0);
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

void	init_convs(t_conversion *convs)
{
	convs->mem_err = true;
	convs->arg_len = 0;
	convs->mem_err = false;
	convs->minus_value = false;
}

//
//void	info_conversion(t_conversion *convs)
//{
//	ft_printf("\ninfo:convs->point:[%s]\n", convs->point);
//	ft_printf("convs->size:%zu\n", convs->size);
//	ft_printf("convs->conversion:%c\n", convs->conversion);
//	ft_printf("convs->mini_width:%d\n", convs->mini_width);
//	ft_printf("convs->precision:%d\n", convs->precision);
//	ft_printf("convs->flag_minus:%d\n", convs->flag_minus);
//	ft_printf("convs->flag_plus:%d\n", convs->flag_plus);
//	ft_printf("convs->flag_sharp:%d\n", convs->flag_sharp);
//	ft_printf("convs->flag_space:%d\n", convs->flag_space);
//	ft_printf("convs->flag_zero:%d\n", convs->flag_zero);
//	ft_printf("convs->valid:%d\n", convs->valid);
//	ft_printf("convs->mem_err:%d\n", convs->mem_err);
//	ft_printf("convs->minus_value:%d\n", convs->minus_value);
//	ft_printf("convs->print_size:%zu\n", convs->print_size);
//}
//
