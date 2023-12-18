/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_hexa_maj.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:13:23 by picatrai          #+#    #+#             */
/*   Updated: 2023/11/13 17:42:39 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(unsigned int nbr, const char *str)
{
	size_t	count;

	count = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		count++;
	while (nbr != 0)
	{
		nbr /= ft_strlen(str);
		count++;
	}
	return (count);
}

static int	ft_fonction(unsigned int nbr, const char *str)
{
	unsigned int	n;
	char			*res;
	int				len;

	if (nbr == 0)
		return (ft_putchar(str[0]));
	n = nbr;
	len = ft_count(nbr, str);
	res = malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (0);
	res[len--] = '\0';
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		res[len--] = str[n % ft_strlen(str)];
		n /= ft_strlen(str);
	}
	if (nbr < 0)
		res[0] = '-';
	ft_putstr(res);
	len = ft_strlen(res);
	free(res);
	return (len);
}

int	ft_putnbr_base_hexa_maj(unsigned int nbr)
{
	return (ft_fonction(nbr, "0123456789ABCDEF"));
}
