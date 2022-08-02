/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 22:44:24 by hsano             #+#    #+#             */
/*   Updated: 2022/08/03 01:35:52 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_char(t_conversion *convs, char *word)
{
	if (convs->conversion == 'c')
		write(1, word, 1);
}

void	put_str(t_conversion *convs, char *word)
{
	if (convs->conversion == 's')
		write(1, word, ft_strlen(word));
}

void	put_point(t_conversion *convs, char *word)
{
	unsigned long long p;

	p = (unsigned long long)word;
	if (convs->conversion == 'p')
		ft_putpointer_base(p, BASE_HEX);
}

void	put_int_digit(t_conversion *convs, int word)
{
	if (convs->conversion == 'a')
		ft_putnbr_base(word, BASE_DIGIT);
	ft_putnbr_base(word, BASE_DIGIT);
}

void	put_int_hex(t_conversion *convs, int word)
{
	if (convs->conversion == 'a')
		ft_putnbr_base(word, BASE_HEX);
	ft_putnbr_base(word, BASE_HEX);
}

