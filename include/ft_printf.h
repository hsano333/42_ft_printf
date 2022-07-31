/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:26:08 by hsano             #+#    #+#             */
/*   Updated: 2022/08/01 00:37:53 by hsano            ###   ########.fr       */
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
# include "../libft/libft.h"

typedef struct s_conversion
{
	size_t							size;
	const char						*point;
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

# endif
enum FLAG { ZERO, PERIOD, SHARP, SPACE, PLUS, MINUS};
enum CONVERSION { CHAR, STRING, POINTER, DECIMAL, INTEGER, UDECIMAL, LOWHEX, UPHEX, PERCENT};

int	ft_atoi_base(char *str, char *base);
size_t	find_conversion(const char *str, int *is_valid);
void	parse_conversion(const char *str,t_conversion *convs);
size_t	check_period(const char *str, int str_size);
size_t ft_atoin(const char* str, size_t size, int *error);
size_t	where_label_last(const char* str, size_t size);
int	exist_char(const char* str, char c,  size_t size);
void clear_conversion(t_conversion* node);


//TEST
# include <stdio.h>
