/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 09:34:44 by hsano             #+#    #+#             */
/*   Updated: 2022/08/03 01:31:29 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
# include <limits.h>

#define TRUE 1
#define FALSE 0
#define SAVED 1
#define ZERO "0 "
#define MINUSSTR "-"
#define LLMIN_STR "-922337203685477580"

void	put_base(unsigned long long nbr, char *base, unsigned int count)
{
	int		i;
	int		tmp_i;
	char	array[100];
	char	swap[100];

	i = 0;
	while (nbr != 0)
	{
		array[i++] = base[nbr % count];
		nbr = nbr / count;
	}
	i--;
	tmp_i = 0;
	while(tmp_i <= i)
	{
		swap[i - tmp_i] = array[tmp_i];
		tmp_i++;
	}
	write(1, swap, tmp_i);
}

unsigned int	check_base(char *base)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (FALSE);
		j = 0;
		while (base[j])
		{
			if ((i != j) && (base[i] == base[j]))
				return (FALSE);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (FALSE);
	return (i);
}

unsigned long long check_min(long long nbr)
{
	if (nbr == LLONG_MIN)
	{
		write(1, &(LLMIN_STR[0]), 19);
		return (0);
	}
	else if (nbr == 0)
	{
		write(1, &(ZERO[0]), 1);
		return (0);
	}
	if (nbr < 0)
	{
		write(1, &(MINUSSTR[0]), 1);
		return (-1);
	}
	return (1);
}


void	ft_putnbr_base(long long nbr, char *base)
{
	int					minus;
	unsigned long long	nbrl;
	unsigned int		count;

	minus = check_min(nbr);
	if (minus == 0)
		return ;
	nbrl = minus * nbr;
	count = check_base(base);
	if (count == FALSE)
		return ;
	if (count > 1)
		put_base(nbrl, base, count);
}

void	ft_putpointer_base(unsigned long long nbrl, char *base)
{
	unsigned int		count;

	if (nbrl == 0)
	{
		write(1, &(NULL_STR[0]), 6);
		return ;
	}
	count = check_base(base);
	if (count == FALSE)
		return ;
	if (count > 1)
		put_base(nbrl, base, count);
}
//#include <stdlib.h>
//#include <stdio.h>
//int main(int argc , char **argv)
//{
//	char *str;
//	char *str2;
//	if (argc == 3)
//	{
//		str = argv[1];
//		str2 = argv[2];
//		ft_putnbr_base(atoi(str),str2);
//		printf("atol:[%d]\n",atoi(str));
//	}
//}
