/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:16:50 by hsano             #+#    #+#             */
/*   Updated: 2022/08/06 00:43:09 by hsano            ###   ########.fr       */
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

static size_t	ft_putstr_fd_wrapper(char *str, int fd)
{
	if (!str)
		return (0);
	ft_putstr_fd(str, fd);
	return (ft_strlen(str));
}

static size_t	print(const char *str, t_list *convs_list, va_list *args)
{
	size_t			i;
	size_t			print_size;
	void			(*del_convs)(void *);
	t_list			*head_convs_list;
	t_conversion	*convs;

	del_convs = (void (*)())clear_conversion;
	i = 0;
	print_size = 0;
	head_convs_list = convs_list;
	while (convs_list)
	{
		convs = (t_conversion *)convs_list->content;
		print_size += (size_t)(convs->point - str - i);
		i += put_raw(&(str[i]), convs);
		i += put_converted_word(convs, args);
		if (convs->mem_err == true)
			break ;
		print_size += convs->print_size;
		convs_list = convs_list->next;
	}
	if (((char *)str)[i])
		print_size += ft_putstr_fd_wrapper(&(((char *)str)[i]), 1);
	ft_lstclear(&head_convs_list, del_convs);
	return (print_size);
}

int	ft_printf(const char *str, ...)
{
	t_list	*c_list;
	va_list	args;

	c_list = parse_str(str);
	va_start(args, str);
	return ((int)(print(str, c_list, &args)));
}
