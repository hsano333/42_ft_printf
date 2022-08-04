/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 22:44:24 by hsano             #+#    #+#             */
/*   Updated: 2022/08/04 15:54:23 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



//void	get_str_char(t_conversion *convs, char word)
char	*get_str_char(va_list* args)
{
	char	word;
	char	*p;

	word = (char)va_arg(*args, int);
	p = malloc(2);
	if (!p)
		return (NULL);
	p[0] = word;
	p[1] = '\0';
	return (p);
}

char	*get_str_str(va_list* args)
{
	char *word;

	word = va_arg(*args, char *);
	return (ft_strdup(word));
}

char	*get_str_point(va_list* args)
{
	//unsigned long long p;
	unsigned long long word;
	//char 				*p;

	//p = va_arg(*args, char*);
	word = (unsigned long long)va_arg(*args, char*);
	//p = (unsigned long long)word;
	//if (convs->conversion == 'p')
	return (ft_strpointer_base(word, BASE_HEX_LOWER));
	//return (0);
}

char	*get_str_int_digit(va_list* args)
{
	int word;

	word = va_arg(*args, int);
	//if (convs->conversion == 'a')
		//ft_strnbr_base(word, BASE_DIGIT);
	return (ft_strnbr_base(word, BASE_DIGIT));
	//return (0);
}

char	*get_str_int_lower_hex(va_list* args)
{
	int word;

	word = va_arg(*args, int);
	//if (convs->conversion == 'a')
		//ft_strnbr_base(word, BASE_HEX);
	return (ft_strnbr_base(word, BASE_HEX_LOWER));
}
char	*get_str_int_upper_hex(va_list* args)
{
	int word;

	word = va_arg(*args, int);
	return (ft_strnbr_base(word, BASE_HEX_UPPER));
}

