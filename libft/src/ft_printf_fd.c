/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:33:24 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/24 14:33:28 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_flags(int fd, char flag, va_list args)
{
	if (flag == 'c')
		return (ft_putchar_fd(va_arg(args, int), fd));
	if (flag == 's')
		return (ft_putstr_fd(va_arg(args, char *), fd));
	if (flag == '%')
		return (ft_putchar_fd('%', fd));
	return (0);
}

int	ft_printf_fd(int fd, const char *type_format, ...)
{
	va_list	args;
	int		i;
	int		result;

	i = 0;
	result = 0;
	if (!type_format)
		return (-1);
	va_start(args, type_format);
	while (type_format[i])
	{
		if (type_format[i] == '%' && type_format[i + 1] != '\0')
			result += ft_flags(fd, type_format[++i], args);
		else
			result += ft_putchar_fd(type_format[i], fd);
		i++;
	}
	va_end(args);
	return (result);
}
