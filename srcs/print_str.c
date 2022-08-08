/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:02:21 by hsano             #+#    #+#             */
/*   Updated: 2022/08/09 03:24:31 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

char	*get_str_char(va_list *args, t_conversion *convs)
{
	int		word_input;
	char	*p;

	word_input = (char)va_arg(*args, int);
	p = malloc(2);
	if (!p)
		return (NULL);
	p[0] = word_input;
	p[1] = '\0';
	convs->mem_err = false;
	convs->arg_len = 1;
	return (p);
}

char	*get_str_str(va_list *args, t_conversion *convs)
{
	//char	*word;
	char	*str;
	size_t	len;

	len = 0;
	str = va_arg(*args, char *);
	convs->not_free = true;
	if (str == NULL)
	{
		convs->not_free = false;
		str = ft_strdup(NULL_STR);
		if (!str)
			return (NULL);
		//len = 6;
	}
	len = ft_strlen(str);
	if (convs->precision == NONE || (size_t)convs->precision > len)
		convs->arg_len = len;
	else if (convs->precision > 0)
		convs->arg_len = convs->precision;
	else
		convs->arg_len = 0;
	convs->mem_err = false;
	return (str);
}

char	*get_str_percent(va_list *args, t_conversion *convs)
{
	char	*str;

	if (!args)
		return (NULL);
	str = ft_strdup("%");
	if (!str)
		return (NULL);
	convs->mem_err = false;
	convs->arg_len = ft_strlen(str);
	if (convs->arg_len >= INT_MAX)
		convs->valid = false;
	return (str);
}

char	*get_str_point(va_list *args, t_conversion *convs)
{
	uintptr_t			word;
	char				*str;
	char				*str_r;

	word = (uintptr_t)va_arg(*args, char *);
	str = ft_strpointer_base(word, BASE_HEX_LOWER);
	if (!str)
		return (NULL);
	else
	{
		str_r = ft_strjoin("0x", str);
		if (!str_r)
			return (NULL);
		free(str);
	}
	convs->mem_err = false;
	convs->arg_len = ft_strlen(str_r);
	return (str_r);
}
