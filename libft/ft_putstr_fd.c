/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:23:11 by hsano             #+#    #+#             */
/*   Updated: 2022/08/05 14:38:31 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	if (!s)
		return (0);
	len = ft_strlen(s);
	return (write(fd, s, len));
}
//#include <stdlib.h>
//int main(int argc, char **argv)
//{
//	char *c;
//	int	fd;
//	if (argc == 3)
//	{
//		c = argv[1];
//		fd = atoi(argv[2]);
//		ft_putstr_fd(c, fd);
//	}
//}
