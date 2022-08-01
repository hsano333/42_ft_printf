/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 15:25:55 by hsano             #+#    #+#             */
/*   Updated: 2022/08/02 00:13:03 by hsano            ###   ########.fr       */
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

int	is_invalid_int_numbers(const char** str, size_t size)
{
	size_t	i;
	size_t	first_digit;

	i = 0;
	while (!('1' <= (*str)[i] && (*str)[i] <= '9') && i < size)
		(i)++;
	first_digit = i;
	while (('0' <= (*str)[i] && (*str)[i] <= '9') && i < size)
		i++;
	if (i - first_digit >= 11)
		return (true);
	*str = &((*str)[first_digit]);
	return (false);
}

size_t ft_atoin(const char* str, size_t size, int *error)
{
	char	*p;
	int		tmp_int;
	int		tmp_error;

	tmp_error = is_invalid_int_numbers(&str, size);
	if (tmp_error)
	{
		*error = true;
		return (0);
	}
	p = ft_substr(str, 0, size);
	if (!p)
	{
		*error = true;
		return (0);
	}
	tmp_int = ft_atoi(p, error);
	free(p);
	if (tmp_int < 0)
	{
		*error = true;
		return (0);
	}
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
	size_t	i;
	char	*p_convs;
	char	*convs_char;

	convs_char = &(VALID_CONVERSIONS[0]);
	*is_valid = true;
	i = 1;
	while (str[i])
	{
		p_convs = ft_strchr(convs_char, (int)(str[i]));

		if (p_convs)
			return (i + 1);
		i++;
	}
	*is_valid = false;
	convs_char = &(INVALID_CONVERSIONS[0]);
	while (str[i])
	{
		p_convs = ft_strchr(convs_char, (int)(str[i]));
		if (p_convs)
			return (i + 1);
		i++;
	}
	return (0);
}

size_t	check_period(const char *str, size_t str_size)
{
	char	*p;
	size_t	i;

	i = 0;
	p = ft_memchr(str, '.', str_size);
	if (p)
		return (p - str);
	return (0);
}
