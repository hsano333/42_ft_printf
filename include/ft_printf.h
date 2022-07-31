/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:26:08 by hsano             #+#    #+#             */
/*   Updated: 2022/07/31 14:12:04 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define VALID_CONVERSIONS "cspdiuxX%%"
# define INVALID_CONVERSIONS "oOfFeEgGl"
# define VALID_FLAG "-0# +"


# include <stdarg.h>
# include <stdio.h>
# include <stdbool.h>

# endif
enum FLAG { ZERO, PERIOD, SHARP, SPACE, PLUS, MINUS};
enum CONVERSION { CHAR, STRING, POINTER, DECIMAL, INTEGER, UDECIMAL, LOWHEX, UPHEX, PERCENT};

int	ft_atoi_base(char *str, char *base);

typedef struct s_conversion
{
	size_t						size;
	char						*point;
	char 						conversion;
	int							mini_width;
	int							precision;
	int							flag_minus;
	int							flag_plus;
	int							flag_sharp;
	int							flag_space;
	int							flag_zero;
	int							valid;
	//enum FLAG					flag;
	//enum CONVERSION				conversion;
}								t_conversion;

//TEST
# include <stdio.h>
