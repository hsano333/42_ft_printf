/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:02:21 by hsano             #+#    #+#             */
/*   Updated: 2022/08/05 11:38:36 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_str_char(va_list *args, t_conversion *convs)
{
	char	word;
	char	*p;

	convs->mem_err = true;
	word = (char)va_arg(*args, int);
	p = malloc(2);
	if (!p)
		return (NULL);
	p[0] = word;
	p[1] = '\0';
	convs->mem_err = false;
	return (p);
}

char	*get_str_str(va_list *args, t_conversion *convs)
{
	char	*word;
	char	*str;
	char	*str_r;

	convs->mem_err = true;
	word = va_arg(*args, char *);
	str = ft_strdup(word);
	if (!str)
		return (NULL);
	str_r = ft_substr(str, 0, convs->precision);
	free(str);
	if (!str_r)
		return (NULL);
	convs->mem_err = false;
	return (str_r);
}

char	*get_str_percent(va_list *args, t_conversion *convs)
{
	char	*str;

	convs->mem_err = true;
	if (!args)
		return (NULL);
	str = ft_strdup("%");
	if (!str)
		return (NULL);
	convs->mem_err = false;
	return (str);
}

char	*get_str_point(va_list *args, t_conversion *convs)
{
	unsigned long long	word;
	char				*str;
	char				*str_r;

	convs->mem_err = true;
	word = (unsigned long long)va_arg(*args, char *);
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
	return (str_r);
}
