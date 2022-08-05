/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:11:22 by hsano             #+#    #+#             */
/*   Updated: 2022/08/05 11:38:13 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	put_flag_minus(t_conversion *convs, char *str, int padding_len,
		char padding)
{
	if (convs->minus_value)
		write(1, "-", 1);
	else if (convs->flag_plus && ft_isdigit(str[0]))
		write(1, "+", 1);
	else if (convs->flag_space && ft_isdigit(str[0]))
		write(1, " ", 1);
	ft_putstr_fd(str, 1);
	while (padding_len--)
		write(1, &padding, 1);
}

void	put_except_flag_minus(t_conversion *convs, char *str, int padding_len,
		char padding)
{
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
	ft_putstr_fd(str, 1);
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
	}
	else if (c == 'c' && convs->mini_width >= 0)
		len = convs->mini_width - 1;
	else if (convs->mini_width > len && convs->mini_width > 0)
		len = convs->mini_width - len;
	else
		len = 0;
	return (len);
}
