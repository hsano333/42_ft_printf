/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:26:08 by hsano             #+#    #+#             */
/*   Updated: 2022/08/04 15:54:02 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define VALID_CONVERSIONS "cspdiuxX%%"
# define INVALID_CONVERSIONS "oOfFeEgGlz"
# define VALID_FLAG "-0# +"
# define BASE_DIGIT "0123456789"
# define BASE_HEX_UPPER "0123456789ABCDEF"
# define BASE_HEX_LOWER "0123456789abcdef"
# define NULL_STR "(null)"
# define FRONT 0
# define BACK 1

# include <stdarg.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
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

int		ft_atoi_base(char *str, char *base, int *err);
size_t	find_conversion(const char *str, int *is_valid);
void	parse_conversion(const char *str,t_conversion *convs);
size_t	check_period(const char *str, size_t str_size);
int		ft_atoin(const char* str, size_t size, int mode, int *error);
size_t	where_label_last(const char* str, size_t size);
int	exist_char(const char* str, char c,  size_t size);
void clear_conversion(t_conversion* node);
void info_conversion(t_conversion *convs);
void	print(const char *str, t_list* c_list, va_list* args);

//void	put_char(t_conversion *convs, char word);
char	*get_str_char(va_list* args);
char	*get_str_str(va_list* args);
char	*get_str_point(va_list* args);
char	*get_str_int_digit(va_list* args);
char	*get_str_int_upper_hex(va_list* args);
char	*get_str_int_lower_hex(va_list* args);
//char	*ft_putnbr_base(t_conversion *convs, va_list* args, int* error);
//char	*ft_putpointer_base(t_conversion *convs, va_list* args, int* error);
char	*ft_strnbr_base(long long nbr, char *base);
char	*ft_strpointer_base(unsigned long long nbrl, char *base);

//TEST
# include <stdio.h>
