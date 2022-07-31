/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 15:25:55 by hsano             #+#    #+#             */
/*   Updated: 2022/08/01 00:42:52 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void clear_conversion(t_conversion* node)
{
	free(node);
}

int	is_valid_int_numbers(const char* str, size_t size)
{
	size_t	i;
	size_t	first_digit;

	i = 0;
	while (!('1' <= str[i] && str[i] <= '9') || i < size)
		(i)++;

	first_digit = i;
	while (('1' <= str[i] && str[i] <= '9') || i < size)
		i++;

	if (first_digit - i + 1 >= 10 || i == size)
		return (false);
	return (true);
}

size_t ft_atoin(const char* str, size_t size, int *error)
{
	char	*p;
	int		tmp_int;

	*error = is_valid_int_numbers(str, size);
	if (error)
		return (0);
	p = ft_substr(str, 0, size);
	if (!p)
	{
		*error = true;
		return (0);
	}
	tmp_int = ft_atoi(p);
	free(p);
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
	i = 0;
	while (convs_char[i])
	{
		p_convs = ft_strchr(str, (int)(convs_char[i]));
		if (p_convs)
			return (p_convs - str);
	}
	*is_valid = false;
	convs_char = &(INVALID_CONVERSIONS[0]);
	while (*convs_char && str[i])
	{
		p_convs = ft_strchr(str, (int)(convs_char[i]));
		if (p_convs)
			return (p_convs - str);
	}
	return (0);
}

size_t	check_period(const char *str, int str_size)
{
	char	*p;
	size_t	i;

	i = 0;
	p = ft_memchr(str, '.', str_size);
	if (p)
		return (p - str);
	return (0);
}
