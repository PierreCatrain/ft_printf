/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:36:48 by picatrai          #+#    #+#             */
/*   Updated: 2023/11/13 17:43:46 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

int	ft_putchar(const int c);
int	ft_putstr(const char *str);
int	ft_putnbr_base(long nbr, const char *str);
int	ft_putnbr_base_unsigned(unsigned int nbr, const char *str);
int	ft_putnbr_base_void(unsigned long nbr, const char *str);
int	ft_putnbr_base_hexa_maj(unsigned int nbr);
int	ft_putnbr_base_hexa_min(unsigned int nbr);
int	ft_strlen(const char *str);
int	ft_printf(const char *str, ...);

#endif
