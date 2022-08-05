/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:26:08 by hsano             #+#    #+#             */
/*   Updated: 2022/08/06 01:22:01 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BASE_DIGIT "0123456789"

# include "../libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
//# include <stdio.h>

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
#endif
