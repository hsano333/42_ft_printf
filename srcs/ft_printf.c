/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:16:50 by hsano             #+#    #+#             */
/*   Updated: 2022/08/04 13:30:46 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_conversion(const char *str, t_conversion *convs)
{
	size_t			middle_point;
	int				is_valid;
	int				error;
	size_t			tmp_size;
	
	error = false;
	tmp_size = find_conversion(str, &is_valid);
	if (tmp_size <= 1)
		return ;
	convs->size = tmp_size;
	convs->point = str;
	middle_point = check_period(str, convs->size);
	if (middle_point == 0)
		middle_point = convs->size - 1;
	//printf("No.0 str=%s\n", str);
	//printf("No.1 str=%s,,middle_point=%zu\n",&(str[middle_point]), middle_point);
	convs->mini_width = ft_atoin(str, middle_point, FRONT, &error);
	//printf("No.1 error=%d\n",error);
	//printf("No.2 str=%s,convs->mini_width=%d,middle_point=%zu\n",&(str[middle_point]),convs->mini_width, middle_point);
	convs->precision = ft_atoin(&(str[middle_point]), convs->size - middle_point - 1, BACK, &error);
	//printf("No.2 error=%d\n",error);
	middle_point = where_label_last(str, middle_point);
	convs->flag_minus = exist_char(str, '-', middle_point);
	convs->flag_plus = exist_char(str, '+', middle_point);
	convs->flag_sharp = exist_char(str, '#', middle_point);
	convs->flag_space = exist_char(str, ' ', middle_point);
	convs->flag_zero = exist_char(str, '0', middle_point);
	convs->valid = is_valid && !error;
	convs->conversion = str[convs->size - 1];
}

t_list *parse_str(const char *str)
{
	const char	*pp;
	t_conversion	*convs;
	t_list			**convs_list;
	t_list			*return_list;
	void (*del_convs)(void*);

	convs_list = (t_list**)malloc(sizeof(t_list**));
	convs_list[0] = NULL;
	del_convs = (void (*)())clear_conversion;
	pp = ft_strchr(str, '%');
	while (pp)
	{
		convs = (t_conversion*)malloc(sizeof(t_conversion));
		if (!convs)
		{
			ft_lstclear(convs_list, del_convs);
			return (NULL);
		}
		parse_conversion(pp, convs);
		ft_lstadd_back(convs_list, ft_lstnew(convs));
		pp = ft_strchr(++pp, '%');
	}
	return_list = convs_list[0];
	free(convs_list);
	return (return_list);
}

void ft_printf(const char *str, ...)
{
	printf("start printf str:%s\n",str);
	//const char	*pp;
	//int			i;
	t_list		*c_list;
	//t_conversion	*tmp;
	va_list args;

	c_list = parse_str(str);
	va_start(args, str);
	print(str, c_list, &args);

	//t_list *tmp_list;
	//tmp_list = c_list[0];
	/*
	while(tmp_list)
	{
		info_conversion(tmp_list->content);
		tmp_list = tmp_list->next;
	}
	*/

	//printf("%s\n",str);
	//tmp = (t_conversion*)c_list[0]->content;
	//printf("%zu",tmp->size);

	/*
	 *
	 *
	pp = va_arg(args, const char*);
	printf("pp1:%s\n",pp);
	pp = va_arg(args, const char*);
	printf("pp2:%s\n",pp);
	*/
	//pp = va_arg(args, const char*);
	//printf("pp3:%s\n",pp);
	/*
	for( const char* p = str; *p != '\0'; ++p ){
		printf("i=%d\n",i++);
		printf("str=%s\n", p);
		pp = va_arg(args, const char*);
		printf("va_arg=%s\n", pp);
	}


	*/

	printf("end\n");
}

