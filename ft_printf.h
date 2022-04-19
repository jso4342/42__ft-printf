/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 20:46:14 by sjang             #+#    #+#             */
/*   Updated: 2020/02/27 17:27:29 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct	s_format
{
	int		neg;
	int		mwf;
	int		zero;
	int		dot;
	int		star;
	int		capital;
	int		len;
	int		formatlen;
	int		width;
	int		prec;
	int		pre;
	int		prer;
	int		starpre;
	int		starstar;
	int		extra;
	int		extra2;
	char	*flags;
}				t_format;

int				ft_printf(const char *format, ...);
void			ft_putchar(char s, t_format *c);
void			convert_c(va_list ap, t_format *c);
void			convert_s(va_list ap, t_format *c);
void			convert_di(va_list ap, t_format *c);
void			convert_p(va_list ap, t_format *c);
void			convert_u(va_list ap, t_format *c);
void			convert_x(va_list ap, t_format *c);
void			ft_check_neg(int n, t_format *c, unsigned int *nbr);
void			convert_percent(va_list ap, t_format *c);
void			ft_base_itoa(unsigned int d, int base, t_format *c);
void			ft_putstr(char *s, t_format *c);
void			ft_putnbr(int n, t_format *c);
void			ft_putstr(char *s, t_format *c);
void			ft_strdel(char *s);
int				ft_howmany_placevalue(unsigned int a, unsigned int base);
int				ft_howmany_placevalue_d(int a, int base);
int				ft_howmany_placevalue_p(unsigned long a, unsigned long base);
int				size_flags(const char *s, t_format *c, int start);
void			ft_set_struct(t_format *c);
void			ft_manage_star(t_format *c, int n, va_list ap);
void			ft_substar(t_format *c, int n);
void			ft_pre_neg(t_format *c, unsigned int n, int k, int j);
void			ft_pre_else(t_format *c, unsigned int n, int k, int j);
void			ft_pre_condition(t_format *c, int n);
void			ft_pre_d_rest(t_format *c, int n, int size, int j);
void			ft_pre_d_neg1(t_format *c, int n, int size, int j);
void			ft_putnbr(int n, t_format *c);
void			ft_pre_rest(t_format *c, unsigned long long n);
void			ft_else(t_format *c, unsigned long long n, int j, int size);
void			add(unsigned long long d, unsigned long long base, t_format *c);
void			ft_pre_neg(t_format *c, unsigned int n, int k, int j);
void			ft_base_itoa(unsigned int d, int n, t_format *c);
void			ft_null(t_format *c, unsigned long long n, int size);
int				check_format(char *extract, t_format *c);
int				check_format2(char *extract, t_format *c, int *i);
int				ft_get_precision(t_format *c, char *extract, int *i);
int				ft_get_width(t_format *c, char *extract, int *i);
char			*save(const char *format, int start, int end, t_format *c);

#endif
