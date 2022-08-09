/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 22:44:24 by hsano             #+#    #+#             */
/*   Updated: 2022/08/09 16:27:25 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

static char	*add_zero(char *src, t_conversion *convs)
{
	int		zero_size;
	char	*dst;
	int		i;
	int		src_len;

	src_len = (int)ft_strlen(src);
	if (src_len >= convs->precision)
		return (src);
	zero_size = convs->precision - src_len;
	dst = malloc(zero_size + src_len + 1);
	if (!dst)
	{
		free(src);
		return (NULL);
	}
	free(src);
	i = 0;
	while (i < zero_size)
		dst[i++] = '0';
	while (src_len--)
	{
		dst[i] = src[i - zero_size];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*get_str_uint_digit(va_list *args, t_conversion *convs)
{
	unsigned int	word;
	char			*str;
	char			*str_r;

	word = va_arg(*args, unsigned int);
	str = ft_strnbr_base(word, BASE_DIGIT);
	if (!str)
		return (NULL);
	if (convs->precision == ZERO && str[0] == '0')
		str[0] = '\0';
	str_r = add_zero(str, convs);
	if (!str_r)
		return (NULL);
	convs->mem_err = false;
	convs->free_str = true;
	convs->arg_len = ft_strlen(str_r);
	return (str_r);
}

char	*get_str_int_digit(va_list *args, t_conversion *convs)
{
	long long	word;
	char		*str;
	char		*str_r;

	word = va_arg(*args, int);
	if (word < 0)
	{
		word = -1 * word;
		convs->minus_value = true;
	}
	str = ft_strnbr_base(word, BASE_DIGIT);
	if (!str)
		return (NULL);
	if (convs->precision == ZERO && str[0] == '0')
		str[0] = '\0';
	str_r = add_zero(str, convs);
	if (!str_r)
		return (NULL);
	convs->mem_err = false;
	convs->free_str = true;
	convs->arg_len = ft_strlen(str_r);
	return (str_r);
}

char	*get_str_int_hex(va_list *args, t_conversion *convs)
{
	unsigned long long	word;
	char				*str;

	word = (unsigned long long)va_arg(*args, unsigned int);
	str = ft_strnbr_base(word, BASE_HEX_UPPER);
	if (!str)
		return (NULL);
	if (convs->precision == ZERO && str[0] == '0')
		str[0] = '\0';
	if (convs->flag_sharp && str[0] != '\0' && word != 0)
	{
		convs->sharp_str[0] = '0';
		convs->sharp_str[1] = convs->conversion;
	}
	str = add_zero(str, convs);
	if (!str)
		return (NULL);
	convs->mem_err = false;
	convs->free_str = true;
	convs->arg_len = ft_strlen(str);
	return (str);
}
