/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 00:40:34 by hsano             #+#    #+#             */
/*   Updated: 2022/08/02 01:10:22 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	print(const char *str, t_list* c_list, va_list* args)
{
	//t_conversion	*conv;
	const char	*pp;

	if (c_list == NULL)
		ft_putstr_fd((char *)str, 1);

		
	//conv = c_list[0].co;
	pp = va_arg(*args, const char*);
	printf("pp=%s/n",pp);

	t_list *tmp_list;
	tmp_list = c_list;
	while(tmp_list)
	{
		info_conversion(tmp_list->content);
		tmp_list = tmp_list->next;
	}

}




