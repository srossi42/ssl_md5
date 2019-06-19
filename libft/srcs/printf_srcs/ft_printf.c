/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:49:56 by srossi            #+#    #+#             */
/*   Updated: 2018/09/11 14:48:59 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_tabptr.h"

static	int	ft_load_format(char *buff, const char *format, t_arg *arg)
{
	arg->eoformat = 0;
	while (format[arg->format_i] && format[arg->format_i] != '%' && BUFF_I <=
			BUFF_SIZE)
	{
		buff[arg->buff_i++] = (char)format[arg->format_i++];
		arg->index++;
		arg->eoformat++;
		if (BUFF_I == BUFF_SIZE)
		{
			write(arg->fd, buff, BUFF_I);
			ft_bzero(buff, BUFF_I);
			BUFF_I = 0;
		}
	}
	return (0);
}

static	int	ft_load_arg(char *buff, t_arg *arg, va_list ap)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 16)
	{
		if (TYPE == tabtype[i].c)
		{
			j = tabtype[i].f_type(buff, arg, ap);
			if (j == -1)
				return (-1);
			arg->format_i++;
		}
		i++;
	}
	return (i);
}

int			ft_load(t_arg *arg, char *buff, va_list ap, const char *format)
{
	while (format[FORMAT_I])
	{
		ft_load_format(buff, format, arg);
		if (format[FORMAT_I])
			FORMAT_I++;
		else
			return (ft_write_end(buff, arg, ap));
		ft_arg_set(&format[FORMAT_I], arg);
		if (ft_istypeconv(TYPE) == -1)
		{
			ft_no_conv(buff, arg);
			if (LN_MAX == 0)
				return (0);
		}
		if (ft_load_arg(buff, arg, ap) == -1)
			return (ft_arg_reset(arg, 2));
		INDEX = INDEX + LN_MAX;
		ft_arg_reset(arg, 1);
	}
	return (ft_write_end(buff, arg, ap));
}

int			ft_dprintf(int fd, const char *format, ...)
{
	t_arg	arg;
	char	buff[BUFF_SIZE + 1];
	va_list ap;

	ft_init_printf(buff, &arg, fd);
	va_start(ap, format);
	if (!format)
		return (-1);
	else
		return (ft_load(&arg, buff, ap, format));
}

int			ft_printf(const char *format, ...)
{
	t_arg	arg;
	char	buff[BUFF_SIZE + 1];
	va_list ap;

	ft_init_printf(buff, &arg, 1);
	va_start(ap, format);
	if (!format)
		return (-1);
	else
		return (ft_load(&arg, buff, ap, format));
}
