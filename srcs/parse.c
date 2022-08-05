/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:16:50 by hsano             #+#    #+#             */
/*   Updated: 2022/08/05 13:54:05 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	find_conversion(const char *str, int *is_valid)
{
	int		percent_flag;
	char	*p_convs;
	char	*convs_char;
	size_t	i;

	convs_char = &(VALID_CONVERSIONS[0]);
	*is_valid = true;
	i = 1;
	percent_flag = false;
	while (str[i])
	{
		p_convs = ft_strchr(convs_char, (int)(str[i++]));
		if (p_convs)
			return (i);
	}
	*is_valid = false;
	convs_char = &(INVALID_CONVERSIONS[0]);
	while (str[i])
	{
		p_convs = ft_strchr(convs_char, (int)(str[i++]));
		if (p_convs)
			return (i);
	}
	return (0);
}

void	parse_conversion(const char *str, t_conversion *convs)
{
	int		is_valid;
	int		error;
	size_t	tmp_size;
	size_t	middle_point;

	error = false;
	tmp_size = find_conversion(str, &is_valid);
	if (tmp_size <= 1)
		return ;
	convs->size = tmp_size;
	convs->point = str;
	middle_point = check_period(str, convs->size);
	convs->mini_width = ft_atoin(str, middle_point, FRONT, &error);
	convs->precision = ft_atoin(&(str[middle_point]), convs->size - middle_point
			- 1, BACK, &error);
	middle_point = where_label_last(str, middle_point);
	convs->flag_minus = exist_char(str, '-', middle_point);
	convs->flag_plus = exist_char(str, '+', middle_point);
	convs->flag_sharp = exist_char(str, '#', middle_point);
	convs->flag_space = exist_char(str, ' ', middle_point);
	convs->flag_zero = exist_char(str, '0', middle_point);
	convs->valid = is_valid && !error;
	convs->conversion = str[convs->size - 1];
	convs->mem_err = false;
	convs->minus_value = false;
}

size_t	check_period(const char *str, size_t str_size)
{
	char	*p;
	size_t	i;
	size_t	tmp_size;

	i = 0;
	p = ft_memchr(str, '.', str_size);
	if (!p)
		return (str_size - 1);
	tmp_size = p - str;
	if (tmp_size == 0)
		return (str_size - 1);
	return (tmp_size);
}

size_t	where_label_last(const char *str, size_t size)
{
	size_t	i;

	if (size == 0)
		return (0);
	i = 0;
	while (str[i] && i < size)
	{
		if ('1' <= str[i] && str[i] <= '9')
			return (i);
		i++;
	}
	return (i);
}

