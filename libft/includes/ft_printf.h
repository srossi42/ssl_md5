/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 17:01:24 by srossi            #+#    #+#             */
/*   Updated: 2018/09/11 14:46:53 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define OPT_TAB_SIZE 5
# define BUFF_SIZE 200

# define INDEX arg->index
# define MEM arg->mem
# define FLAGS arg->c_flags
# define PRECISION arg->precision
# define F_PREC arg->f_prec
# define SIZE arg->size
# define WIDTH arg->width
# define COUNTER arg->counter
# define NB_BITS arg->counter
# define TYPE arg->type_conv
# define F_NEG arg->f_neg
# define ARG_NB arg->arg_nb
# define ARG_UL_NB arg->arg_ul_nb
# define ARG_STR arg->arg_str
# define LN_MAX arg->ln_max
# define NB_LN arg->nb_ln
# define NB_ZEROS arg->nb_zeros
# define NB_SPACES arg->nb_spaces
# define BUFF_I arg->buff_i
# define FORMAT_I arg->format_i
# define STR_TMP arg->str_tmp

# define F_NONE 0
# define F_MINUS (1<<0)
# define F_ZERO (1<<1)
# define F_PLUS (1<<2)
# define F_BLANK (1<<3)
# define F_HASH (1<<4)

# define H (1 << 0)
# define HH (1 << 1)
# define L (1 << 2)
# define LL (1 << 3)
# define J (1 << 4)
# define Z (1 << 5)

# include "libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <inttypes.h>
# include <wchar.h>
# include <limits.h>
# include <locale.h>

typedef struct				s_arg
{
	int						fd;
	int						s_null;
	int						index;
	int						ln_max;
	char					c_flags;
	int						width;
	int						precision;
	char					size;
	char					type_conv;
	int						counter;
	int						f_prec;
	int						f_neg;
	int						nb_ln;
	int						nb_spaces;
	int						nb_zeros;
	long long				arg_nb;
	unsigned long long		arg_ul_nb;
	char					*arg_str;
	int						format_i;
	int						buff_i;
	int						eoformat;
	int						mem;
	char					*str_tmp;
}							t_arg;

int							ft_arg_clean(t_arg *arg);
void						ft_arg_display(t_arg *arg);
void						ft_arg_print(char *buff, t_arg *arg, char *arg_str);
int							ft_arg_reset(t_arg *arg, int n);
int							ft_arg_set(const char *str, t_arg *arg);
uintmax_t					ft_cast_us(t_arg *arg, va_list ap);
intmax_t					ft_cast_s(t_arg *arg, va_list ap);
int							ft_conv_nb(char *str, t_arg *arg, va_list ap);
int							ft_conv_s(char *str, t_arg *arg, va_list ap);
int							ft_conv_c(char *str, t_arg *arg, va_list ap);
int							ft_conv_wc(t_arg *arg, wchar_t c);
int							ft_conv_wchar(char *str, t_arg *arg, va_list ap);
int							ft_conv_wchar_s(char *str, t_arg *arg, va_list ap);
int							ft_conv_percent(char *str, t_arg *arg, va_list ap);
int							ft_conv_p(char *str, t_arg *arg, va_list ap);
int							ft_conv_x(char *str, t_arg *arg, va_list ap);
void						ft_def_nb_space(t_arg *arg);
void						ft_def_nb_str(t_arg *arg, va_list ap);
void						ft_def_nb_zero(t_arg *arg);
void						ft_def_ln_max(t_arg *arg);
void						ft_def_x_lnmax(t_arg *arg);
void						ft_def_x_space(t_arg *arg);
void						ft_def_x_str(t_arg *arg, va_list ap);
void						ft_def_x_zero(t_arg *arg);
int							ft_fill_nchar(char *str, char c, int nb);
int							ft_isflag(char c);
int							ft_isprecision(char *str);
int							ft_issize(char c);
int							ft_istypeconv(char c);
int							ft_no_conv(char *str, t_arg *arg);
int							ft_printf(const char *format, ...);
void						ft_str_null(t_arg *arg);
void						ft_strlen_wchar(wchar_t *c, t_arg *arg);
void						ft_unicode_4(wchar_t *c, char str[5]);
void						ft_unicode_3(wchar_t *c, char str[5]);
void						ft_unicode_2(wchar_t *c, char str[5]);
void						ft_unicode_1(wchar_t *c, char str[5]);
int							ft_write_buff(char *buff, t_arg *arg);
int							ft_write_end(char *buff, t_arg *arg, va_list ap);
int							ft_write_wchar(char *buff, t_arg *arg);
int							ft_init_printf(char *buff, t_arg *arg, int fd);
int							ft_dprintf(int fd, const char *format, ...);
int							ft_load(t_arg *arg, char *buff, va_list ap\
		, const char *format);
int							ft_init_printf(char *buff, t_arg *arg, int fd);

#endif
