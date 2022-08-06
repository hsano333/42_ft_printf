/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:26:08 by hsano             #+#    #+#             */
/*   Updated: 2022/08/07 00:18:59 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
//# define CONVERSIONS_CHAR "cspdiuxX%% .#+-0123456789oOfFeEgGlz"
# define CONVERSIONS_CHAR "cspdiuxX% .#+-0123456789"
# define VALID_CONVERSIONS "cspdiuxX%"
# define INVALID_CONVERSIONS "oOfFeEgGlz"
# define FRONT 0
# define BACK 1
# include "common.h"
int				ft_atoi_base(char *str, char *base, int *err);
int				ft_atoin(const char *str, size_t size, int mode);
int				exist_char(const char *str, char c, size_t size);
void			info_conversion(t_conversion *convs);
void			init_convs(t_conversion *convs);
t_list			*parse_str(const char *str);
#endif
