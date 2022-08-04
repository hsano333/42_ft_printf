/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 15:25:55 by hsano             #+#    #+#             */
/*   Updated: 2022/08/05 03:45:02 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void info_conversion(t_conversion *convs)
{
	printf("\ninfo:convs->point:[%s]",convs->point);
	printf("convs->size:%zu\n",convs->size);
	printf("convs->conversion:%c\n",convs->conversion);
	printf("convs->mini_width:%d\n",convs->mini_width);
	printf("convs->precision:%d\n",convs->precision);
	printf("convs->flag_minus:%d\n",convs->flag_minus);
	printf("convs->flag_plus:%d\n",convs->flag_plus);
	printf("convs->flag_sharp:%d\n",convs->flag_sharp);
	printf("convs->flag_space:%d\n",convs->flag_space);
	printf("convs->flag_zero:%d\n",convs->flag_zero);
	printf("convs->valid:%d\n",convs->valid);
}

void clear_conversion(t_conversion* node)
{
	free(node);
}

int	is_invalid_int_numbers(const char** str, size_t size, int mode)
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

int	ft_atoin(const char* str, size_t size, int mode, int *error)
{
	char	*p;
	int		tmp_int;
	int		tmp_error;

	//printf("No.1 size=%zu, str=%s",size,str);
	tmp_error = is_invalid_int_numbers(&str, size, mode);
	if (tmp_error)
	{
		*error = true;
		return (-2);
	}
	//printf("No.2 size=%zu, str=%s",size,str);
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
	//if (size == 0 || (tmp_int == 0 && p[size - 1] != '0'))
		//return (-1);
	return (tmp_int);
}

size_t	where_label_last(const char* str, size_t size)
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

int	exist_char(const char* str, char c,  size_t size)
{
	if (ft_memchr(str, c, size))
		return (true);
	return (false);
}

size_t	find_conversion(const char *str, int *is_valid)
{
	int		percent_flag;
	size_t	i;
	char	*p_convs;
	char	*convs_char;

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
