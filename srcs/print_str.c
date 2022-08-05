/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:02:21 by hsano             #+#    #+#             */
/*   Updated: 2022/08/06 01:02:54 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "print.h"

char	*get_str_char(va_list *args, t_conversion *convs)
{
	int		word_input;
	char	word;
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
	char	*word;
	char	*str;
	char	*str_r;

	word = va_arg(*args, char *);
	if (word == NULL)
		str = ft_strdup(NULL_STR);
	else
		str = ft_strdup(word);
	if (!str)
		return (NULL);
	str_r = ft_substr(str, 0, convs->precision);
	free(str);
	if (!str_r)
		return (NULL);
	convs->mem_err = false;
	convs->arg_len = ft_strlen(str_r);
	return (str_r);
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
	return (str);
}

char	*get_str_point(va_list *args, t_conversion *convs)
{
	unsigned long long	word;
	char				*str;
	char				*str_r;

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
	convs->arg_len = ft_strlen(str_r);
	return (str_r);
}
