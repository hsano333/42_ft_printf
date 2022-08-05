/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:26:08 by hsano             #+#    #+#             */
/*   Updated: 2022/08/06 00:41:48 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define VALID_CONVERSIONS "cspdiuxX%"
# define INVALID_CONVERSIONS "oOfFeEgGlz"
# define VALID_FLAG "-0# +"
# define BASE_DIGIT "0123456789"
# define BASE_HEX_UPPER "0123456789ABCDEF"
# define BASE_HEX_LOWER "0123456789abcdef"
# define NULL_STR "(null)"
# define FRONT 0
# define BACK 1

# include "../libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_conversion
{
	size_t		size;
	const char	*point;
	char		conversion;
	int			mini_width;
	int			precision;
	int			flag_minus;
	int			flag_plus;
	int			flag_sharp;
	int			flag_space;
	int			flag_zero;
	int			valid;
	int			mem_err;
	int			minus_value;
	size_t		arg_len;
	size_t		print_size;
}				t_conversion;

int				ft_atoi_base(char *str, char *base, int *err);
size_t			find_conversion(const char *str, int *is_valid);
void			parse_conversion(const char *str, t_conversion *convs);
size_t			check_period(const char *str, size_t str_size);
int				ft_atoin(const char *str, size_t size, int mode, int *error);
size_t			where_label_last(const char *str, size_t size);
int				exist_char(const char *str, char c, size_t size);
void			clear_conversion(t_conversion *node);
void			info_conversion(t_conversion *convs);
char			*get_str_char(va_list *args, t_conversion *convs);
char			*get_str_str(va_list *args, t_conversion *convs);
char			*get_str_point(va_list *args, t_conversion *convs);
char			*get_str_int_digit(va_list *args, t_conversion *convs);
char			*get_str_uint_digit(va_list *args, t_conversion *convs);
char			*get_str_int_upper_hex(va_list *args, t_conversion *convs);
char			*get_str_int_lower_hex(va_list *args, t_conversion *convs);
char			*get_str_percent(va_list *args, t_conversion *convs);
char			*ft_strnbr_base(long long nbr, char *base);
char			*ft_strpointer_base(unsigned long long nbrl, char *base);
int				get_padding_len(t_conversion *convs, char *str, int str_len);
size_t			put_flag_minus(t_conversion *convs, char *str, \
				int padding_len, char padding);
size_t			put_except_minus(t_conversion *convs, char *str, \
				int padding_len, char padding);
size_t			put_raw(const char *str, t_conversion *convs);
size_t			put_converted_word(t_conversion *convs, va_list *args);
#endif
