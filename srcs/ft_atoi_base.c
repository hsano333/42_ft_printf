/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:39:54 by hsano             #+#    #+#             */
/*   Updated: 2022/08/01 23:24:29 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TRUE 1
#define FALSE 0
#define MINUS (-1)
#define PLUSMINUS (1)
#define OTHER 2
#define SPACE 3
#define NUMBER 4
#define FIRST 1
#define SECOND 2
#define THIRD 3
#define ERROR -2

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
		else if (base[i] == ' ' || (base[i] >= 0x09 && base[i] <= 0x0D))
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

int	check_word(char c, char *base, unsigned int *minus_cnt)
{
	int	i;

	if (c == '+')
		return (PLUSMINUS);
	else if (c == ' ' || (c >= 0x09 && c <= 0x0D))
		return (SPACE);
	else if (c == '-')
	{
		(*minus_cnt)++;
		return (PLUSMINUS);
	}
	else
	{
		i = 0;
		while (base[i])
		{
			if (c == base[i])
				return (NUMBER);
			i++;
		}
	}
	return (FALSE);
}

void	set_number(char *dest, char *src, unsigned int *c, char *base)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	cnt;
	int				zero_flag;

	i = 0;
	*c = 0;
	zero_flag = FALSE;
	while (src[i] && check_word(src[i], base, &cnt) == NUMBER)
	{
		j = 0;
		while (base[j])
		{
			if (src[i] == base[j] && (zero_flag || j > 0))
			{
				dest[*c] = j;
				(*c)++;
				zero_flag = TRUE;
				break ;
			}
			j++;
		}
		i++;
	}
	dest[*c] = '\0';
}

int	convert_char(char *char_array, char *str, char *base, unsigned int *size)
{
	unsigned int	minus_cnt;
	unsigned int	tmp;

	*size = 0;
	minus_cnt = 0;
	while (check_word(str[*size], base, &tmp) == SPACE)
		(*size)++;
	if (check_word(str[*size], base, &tmp) == FALSE)
		return (ERROR);
	while (check_word(str[*size], base, &minus_cnt) == PLUSMINUS)
		(*size)++;
	if (check_word(str[*size], base, &tmp) != NUMBER)
		return (ERROR);
	set_number(&(char_array[0]), &(str[*size]), size, base);
	return (minus_cnt);
}

int	ft_atoi_base(char *str, char *base)
{
	unsigned int	array_size;
	int				count;
	char			char_array[200];
	int				rval;
	unsigned int	tmp;

	count = check_base(base);
	if (convert_char(char_array, str, base, &array_size) == ERROR)
		return (FALSE);
	if (array_size == 0 || count <= 1)
		return (FALSE);
	array_size -= 1;
	rval = char_array[array_size];
	tmp = 1;
	while (array_size)
	{
		array_size--;
		tmp *= count;
		rval += char_array[array_size] * tmp;
	}
	if (convert_char(char_array, str, base, &array_size) % 2 == 1)
		return (rval * MINUS);
	return (rval);
}
//int main(int argc , char **argv)
//{
//	char *str;
//	char *str2;
//	if (argc == 3)
//	{
//		str = argv[1];
//		str2 = argv[2];
//		printf("my  :[%d]\n",ft_atoi_base(str,str2));
//		printf("atol:[%d]\n",atoi(str));
//	}
//}