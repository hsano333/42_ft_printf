/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:26:08 by hsano             #+#    #+#             */
/*   Updated: 2022/08/06 01:20:32 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# define VALID_CONVERSIONS "cspdiuxX%"
# define INVALID_CONVERSIONS "oOfFeEgGlz"
# define FRONT 0
# define BACK 1

# include "ft_printf.h"

int				ft_atoi_base(char *str, char *base, int *err);
size_t			find_conversion(const char *str, int *is_valid);
void			parse_conversion(const char *str, t_conversion *convs);
size_t			check_period(const char *str, size_t str_size);
int				ft_atoin(const char *str, size_t size, int mode, int *error);
size_t			where_label_last(const char *str, size_t size);
int				exist_char(const char *str, char c, size_t size);
void			clear_conversion(t_conversion *node);
void			info_conversion(t_conversion *convs);
#endif
