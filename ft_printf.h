/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorperei <jorperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 17:23:23 by jorperei          #+#    #+#             */
/*   Updated: 2026/11/25 16:12:32 by jorperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int	ft_hexu(unsigned long n);
int	ft_hexl(unsigned long n);
int	ft_pptr(void *ptr);
int	ft_pstring(char *s);
int	ft_putnb(int n);
int	ft_putnbhexlc(unsigned int n);
int	ft_putnbhexuc(unsigned int n);
int	ft_putunsignednb(unsigned int n);
int	ft_sc(char c);
int	ft_printf(const char *tp, ...);

#endif