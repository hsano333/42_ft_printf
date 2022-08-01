/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 00:40:34 by hsano             #+#    #+#             */
/*   Updated: 2022/08/02 01:44:26 by hsano            ###   ########.fr       */
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
/*
void	put_converted_word(char *str, t_conversion *convs, va_list* args)
{

}
*/
void	print(const char *str, t_list* c_list, va_list* args)
{
	//t_conversion	*conv;
	const char	*pp;
	size_t		i;

	if (c_list == NULL)
		ft_putstr_fd((char *)str, 1);
	//conv = c_list[0].co;
	pp = va_arg(*args, const char*);
	printf("pp=%s/n",pp);

	t_list *tmp_list;
	tmp_list = c_list;
	i = 0;
	while(tmp_list)
	{
		i += put_raw(&(str[i]), tmp_list->content);
		i += return_size(tmp_list->content);
		//put_converted_word();
		//info_conversion(tmp_list->content);
		tmp_list = tmp_list->next;
	}
	ft_putstr_fd((char*)&(str[i]), 1);

}




