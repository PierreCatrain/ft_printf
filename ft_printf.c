/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:44:42 by picatrai          #+#    #+#             */
/*   Updated: 2023/11/13 17:47:22 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_occurence(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_condition(const char *str, int i, va_list arg_list)
{
	int	count;

	count = 0;
	if (str[i] == '%' && str[i + 1] == 'c')
		return (ft_putchar(va_arg(arg_list, int)));
	else if (str[i] == '%' && str[i + 1] == 's')
		return (ft_putstr(va_arg(arg_list, char *)));
	else if (str[i] == '%' && str[i + 1] == 'p')
		return (ft_putnbr_base_void((unsigned long)va_arg(arg_list, void *), \
					"0123456789abcdef"));
	else if (str[i] == '%' && str[i + 1] == 'd')
		return (ft_putnbr_base(va_arg(arg_list, int), "0123456789"));
	else if (str[i] == '%' && str[i + 1] == 'i')
		return (ft_putnbr_base(va_arg(arg_list, int), "0123456789"));
	else if (str[i] == '%' && str[i + 1] == 'u')
		return (ft_putnbr_base_unsigned(va_arg(arg_list, unsigned int), \
					"0123456789"));
	else if (str[i] == '%' && str[i + 1] == 'x')
		return (ft_putnbr_base_hexa_min(va_arg(arg_list, unsigned int)));
	else if (str[i] == '%' && str[i + 1] == 'X')
		return (ft_putnbr_base_hexa_maj(va_arg(arg_list, unsigned int)));
	else if (str[i] == '%' && str[i + 1] == '%')
		return (ft_putchar('%'));
	else
		return (ft_putchar(str[i]));
}

int	ft_printf(const char *str, ...)
{
	va_list	arg_list;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(arg_list, str);
	while (str[i])
	{
		count += ft_condition(str, i, arg_list);
		if (str[i] == '%' && \
		(ft_occurence(str[i + 1], "cspdiuxX") || str[i + 1] == '%'))
			i++;
		i++;
	}
	va_end(arg_list);
	return (count);
}
