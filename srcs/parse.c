/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:16:50 by hsano             #+#    #+#             */
/*   Updated: 2022/08/06 16:15:44 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "common.h"

size_t	find_conversion(const char *str, int *is_valid)
{
	char	*p_convs;
	size_t	i;
	size_t	j;

	i = 1;
	*is_valid = false;
	p_convs = NULL;
	while (str[i])
	{
		p_convs = ft_strchr(&(VALID_CONVERSIONS[0]), (int)(str[i++]));
		if (p_convs)
			break ;
	}
	j = 1;
	while (j < i)
	{
		if (ft_strchr(&(INVALID_CONVERSIONS[0]), (int)(str[j++])))
			return (j);
	}
	if (p_convs == NULL)
		return (1);
	if (ft_strchr(&(VALID_CONVERSIONS[0]), p_convs[0]))
		*is_valid = true;
	return (i);
}

size_t	check_period(const char *str, size_t str_size)
{
	char	*p;
	size_t	i;
	size_t	tmp_size;

	i = 0;
	p = ft_memchr(str, '.', str_size);
	if (!p)
		return (str_size - 1);
	tmp_size = p - str;
	if (tmp_size == 0)
		return (str_size - 1);
	return (tmp_size);
}

size_t	where_label_last(const char *str, size_t size)
{
	size_t	i;

	i = 0;
	while (str[i] && i < size)
	{
		if ('1' <= str[i] && str[i] <= '9')
			return (i);
		i++;
	}
	return (i);
}

void	parse_conversion(const char *str, t_conversion *convs)
{
	int		error;
	size_t	middle_point;

	error = false;
	init_convs(convs);
	convs->size = find_conversion(str, &convs->valid);
	convs->point = str;
	middle_point = check_period(str, convs->size);
	convs->mini_width = ft_atoin(str, middle_point, FRONT);
	convs->precision = ft_atoin(&(str[middle_point]), \
			convs->size - middle_point - 1, BACK);
	middle_point = where_label_last(str, middle_point);
	convs->flag_minus = exist_char(str, '-', middle_point);
	convs->flag_plus = exist_char(str, '+', middle_point);
	convs->flag_sharp = exist_char(str, '#', middle_point);
	convs->flag_space = exist_char(str, ' ', middle_point);
	convs->flag_zero = exist_char(str, '0', middle_point);
	convs->conversion = str[convs->size - 1];
}

t_list	*parse_str(const char *str)
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
