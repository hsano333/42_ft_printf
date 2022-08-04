/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 00:40:34 by hsano             #+#    #+#             */
/*   Updated: 2022/08/05 03:32:54 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


size_t	put_raw(const char *str, t_conversion *convs)
{
	size_t	len;

	len = convs->point - str;
	write(1, str, len);
	return (len);
}

size_t	get_len(t_conversion *convs)
{
	size_t	len;

	len = convs->mini_width;
	if (convs->conversion == 's')
		len = convs->precision;
	else if (convs->conversion == 'c')
		len = 1;
	else
		len = 0;
	return (len);
}

int	get_padding_len(t_conversion *convs, char *str, int str_len)
{
	int		len;
	char	c;

	c = convs->conversion;
	len = str_len;
	if (convs->minus_value)
		len++;
	else if ((convs->flag_plus || convs->flag_space) && ft_isdigit(str[0]))
		len++;
	if (c == 's')
	{
		if (convs->mini_width > str_len && convs->mini_width >= 0)
			len = convs->mini_width - str_len;
		else
			len = 0;
		//printf(" No.1 convs->mini_width=%d, str_len=%d,len=%d\n",convs->mini_width, str_len, len);
	}
	else if (c == 'c' && convs->mini_width >= 0)
		len = convs->mini_width - 1;
	else if (convs->mini_width > len && convs->mini_width > 0)
		len = convs->mini_width - len;
	else
		len = 0;
	return (len);
}

int	get_prefix_len(t_conversion *convs, char *str, int str_len)
{
	int		len;
	char	c;

	c = convs->conversion;
	len = str_len;
	if (convs->flag_sharp)
		len += 2;
	if ((convs->flag_plus || convs->flag_space) && ft_isdigit(str[0]))
		len++;
	if(c == 'd' || c == 'u' || c == 'i' || c == 'x' || c == 'X')
	{
		if (convs->precision >= convs->mini_width && convs->precision > 0)
			len = convs->precision - len;
		else
			len = 0;
	}
	else
		len = 0;
	return (len);
}

/*
int	get_str_len(t_conversion *convs, char *str)
{
	int	str_len;

	str_len = ft_strlen(str);
	//printf("convs->precision=%d\n",convs->precision);
	if (convs->conversion == 's' && convs->precision >= 0)
		str_len = convs->precision;
	//else if (convs->mini_width > str_len)
		//str_len = convs->mini_width;
	return (str_len);
}
*/

int	put_word(t_conversion *convs, va_list* args, char*(*get_str)(va_list*, t_conversion *convs))
{
	char			padding;
	char			*str;
	int				padding_len;
	int				str_len;
	//int				prefix_len;

	//len = get_len(convs);
	str = get_str(args, convs);
	if (!str)
		return (-1);
	str_len = ft_strlen(str);
	//printf("No.1 str_len=%d,convs->precision=%d\n",str_len,convs->precision);
	//str[str_len] = '\0';
	padding_len = get_padding_len(convs, str, str_len);
	//prefix_len = get_prefix_len(convs, str, str_len);
	//printf("No.2 padding_len=%d,convs->mini_width=%d\n",padding_len,convs->mini_width);
	padding = ' ';
	if ((convs->flag_zero)  && !convs->flag_minus)
		padding = '0';
	if (convs->flag_minus)
	{
		if (convs->minus_value)
			write(1, "-", 1);
		else if (convs->flag_plus && ft_isdigit(str[0]))
			write(1, "+", 1);
		else if (convs->flag_space && ft_isdigit(str[0]))
			write(1, " ", 1);
		//while (prefix_len--)
			//write(1, "0", 1);
		ft_putstr_fd(str, 1);
		while (padding_len--)
			write(1, &padding, 1);
		free(str);
		return (true);
	}
	//printf("No.2 padding_len=%d,padding=[%c]\n",padding_len,padding);
	while (padding == ' ' && padding_len--)
		write(1, &padding, 1);
	if (convs->minus_value)
		write(1, "-", 1);
	else if (convs->flag_plus && ft_isdigit(str[0]))
		write(1, "+", 1);
	else if (convs->flag_space && ft_isdigit(str[0]))
		write(1, " ", 1);
	while (padding == '0' && padding_len--)
		write(1, &padding, 1);
	//while (prefix_len--)
		//write(1, "0", 1);
	ft_putstr_fd(str, 1);
	free(str);
	return (true);
}

void	swtiching_valid(t_conversion *convs)
{
	char	c;

	c = convs->conversion;
	if (c == 'c' || c == 's' || c == 'u')
	{
		convs->flag_plus = false;
		convs->flag_sharp = false;
		convs->flag_space = false;
	}
	else if (c == 'p')
	{
		convs->flag_minus = false;
		convs->flag_plus = false;
		convs->flag_space = false;
		convs->flag_zero = false;
		convs->flag_sharp = true;
	}
	else if (c == 'd' || c == 'i')
	{
		convs->flag_sharp = false;
	}
	else if (c == 'x' || c == 'X')
	{
		convs->flag_plus = false;
		convs->flag_space = false;
	}
	else if (c == 'u')
	{
		convs->flag_plus = false;
		convs->flag_space = false;
		convs->flag_sharp = false;
	}
}

size_t	put_converted_word(t_conversion *convs, va_list* args, int *error)
{
	//printf("test put word \n");
	if (convs->valid == false)
		return (write(1, convs->point, convs->size));
	swtiching_valid(convs);
	if (convs->conversion == 'c')
		*error = put_word(convs, args, get_str_char);
	else if (convs->conversion == 's')
		*error = put_word(convs, args, get_str_str);
	else if (convs->conversion == 'p')
		*error = put_word(convs, args, get_str_point);
	else if (convs->conversion == 'd')
		*error = put_word(convs, args, get_str_int_digit);
	else if (convs->conversion == 'i')
		*error = put_word(convs, args, get_str_int_digit);
	else if (convs->conversion == 'u')
		*error = put_word(convs, args, get_str_uint_digit);
	else if (convs->conversion == 'x')
		*error = put_word(convs, args, get_str_int_lower_hex);
	else if (convs->conversion == 'X')
		*error = put_word(convs, args, get_str_int_upper_hex);
	else if (convs->conversion == '%')
		*error = put_word(convs, args, get_str_percent);
	return (convs->size);
}


void	print(const char *str, t_list* c_list, va_list* args)
{
	int	error;
	//t_conversion	*conv;
	//const char	*pp;
	size_t		i;

	error = true;
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
		i += put_converted_word(tmp_list->content, args, &error);
		//i += return_size(tmp_list->content);
		//info_conversion(tmp_list->content);
		if (error == false)
			return ;
		tmp_list = tmp_list->next;
	}
	ft_putstr_fd((char*)&(str[i]), 1);

}




