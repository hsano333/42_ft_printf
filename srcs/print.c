/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 00:40:34 by hsano             #+#    #+#             */
/*   Updated: 2022/08/03 00:56:42 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	put_raw(const char *str, t_conversion *convs)
{
	size_t	len;

	len = convs->point - str;
	//printf("write test No,1 len=%zu\n",len);
	write(1, str, len);
	return (len);
}

size_t	return_size( t_conversion *convs)
{

	return (convs->size);
}

size_t	put_converted_word(t_conversion *convs, va_list* args)
{
	size_t	len;

	len = 0;
	//printf("str:[%s]\n",str[0]);
	//pp = va_arg(*args, const char*);
	if (convs->conversion == 'c')
		put_char(convs, va_arg(*args, char*));
	else if (convs->conversion == 's')
		put_str(convs, va_arg(*args, char*));
	else if (convs->conversion == 'p')
		put_point(convs, va_arg(*args, char*));
	else if (convs->conversion == 'd')
		put_int_digit(convs, va_arg(*args, int));
	else if (convs->conversion == 'i')
		put_int_digit(convs, va_arg(*args, int));
	else if (convs->conversion == 'u')
		put_int_digit(convs, va_arg(*args, int));
	else if (convs->conversion == 'x')
		put_int_hex(convs, va_arg(*args, int));
	else if (convs->conversion == 'X')
		put_int_hex(convs, va_arg(*args, int));
	return (convs->size);
}

void	print(const char *str, t_list* c_list, va_list* args)
{
	//t_conversion	*conv;
	//const char	*pp;
	size_t		i;

	if (c_list == NULL)
		ft_putstr_fd((char *)str, 1);
	//conv = c_list[0].co;
	//pp = va_arg(*args, const char*);
	//printf("pp=%s/n",pp);

	t_list *tmp_list;
	tmp_list = c_list;
	i = 0;
	while(tmp_list)
	{
		i += put_raw(&(str[i]), tmp_list->content);
		i += put_converted_word(tmp_list->content, args);
		//i += return_size(tmp_list->content);
		//info_conversion(tmp_list->content);
		tmp_list = tmp_list->next;
	}
	ft_putstr_fd((char*)&(str[i]), 1);

}




