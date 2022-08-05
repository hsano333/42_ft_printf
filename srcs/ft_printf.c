/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:16:50 by hsano             #+#    #+#             */
/*   Updated: 2022/08/05 16:52:42 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_list	*parse_str(const char *str)
{
	const char		*pp;
	t_conversion	*convs;
	t_list			**convs_list;
	t_list			*return_list;
	void			(*del_convs)(void *);

	convs_list = (t_list **)malloc(sizeof(t_list **));
	convs_list[0] = NULL;
	del_convs = (void (*)())clear_conversion;
	pp = ft_strchr(str, '%');
	while (pp)
	{
		convs = (t_conversion *)malloc(sizeof(t_conversion));
		if (!convs)
		{
			ft_lstclear(convs_list, del_convs);
			return (NULL);
		}
		parse_conversion(pp, convs);
		ft_lstadd_back(convs_list, ft_lstnew(convs));
		pp = ft_strchr(pp + convs->size, '%');
	}
	return_list = convs_list[0];
	free(convs_list);
	return (return_list);
}

static size_t	print(const char *str, t_list *convs_list, va_list *args)
{
	int		error;
	size_t	i;
	size_t	print_size;
	t_conversion *convs;
	void			(*del_convs)(void *);

	del_convs = (void (*)())clear_conversion;
	error = true;
	i = 0;
	print_size = 0;
	while (convs_list)
	{
		convs = (t_conversion *)convs_list->content;
		i += put_raw(&(str[i]), convs);
		i += put_converted_word(convs, args, &error);
		if (error == false)
			return (0);
		print_size += convs->print_size;
		//info_conversion(convs);
		convs_list = convs_list->next;
	}
	if (convs_list == NULL)
		print_size += ft_putstr_fd(&(((char *)str)[i]), 1);
	ft_lstclear(&convs_list, del_convs);
	return (print_size);
}

int	ft_printf(const char *str, ...)
{
	t_list	*c_list;
	va_list	args;

	c_list = parse_str(str);
	va_start(args, str);
	return (int)(print(str, c_list, &args));
}
