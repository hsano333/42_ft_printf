/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 00:53:22 by hsano             #+#    #+#             */
/*   Updated: 2022/08/06 15:18:42 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H
# define BASE_HEX_UPPER "0123456789ABCDEF"
# define BASE_HEX_LOWER "0123456789abcdef"
# define NULL_STR "(null)"

# include "common.h"

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
size_t			ft_putstr_fd_wrapper(char *str, int fd);
int				print(const char *str, t_list *convs_list, va_list *args);
void	info_conversion(t_conversion *convs);
#endif
