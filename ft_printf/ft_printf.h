/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:43:11 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/02/22 16:50:40 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

void	ft_putchar(char c, int *count);
void	ft_putstr(char *s, int *count);
void	ft_putnbr(long n, int *count);
char	*ft_loadstr(long n, long size);
char	*ft_itoa(long n);
int		ft_printf(char const *str, ...);
void	ft_switch(char const *str, int *len, va_list ptr, int *count);
void	ft_putbase(long num, char *base, int *count);
int		ft_strlen(char *str);
void	ft_putptr(unsigned long num, char *base, int *count);

#endif
