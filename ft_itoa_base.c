/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 10:06:53 by exam              #+#    #+#             */
/*   Updated: 2017/04/20 22:39:36 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa_base(int value, int base)
{
	int		i;
	int		sig;
	long	nb;
	long	lvalue;
	char	*str;

	sig = 0;
	lvalue = value;
	if (lvalue < 0 && base == 10)
		sig = 1;
	if (lvalue < 0)
		lvalue = -lvalue;
	nb = lvalue;
	i = 0;
	while (nb > 0)
	{
		nb = nb / base;
		i++;
	}
	if (!(str = (char*)malloc(sizeof(char) * (i + sig))))
		return (NULL);
	nb = i + sig;
	while (nb >= 0)
		str[nb--] = 0;
	i--;
	if (value == 0)
	{
		*str = '0';
		return (str);
	}
	while (i + sig >= 0 && lvalue > 0)
	{
		if (lvalue % base < 10)
			str[i + sig] = lvalue % base + '0';
		else if (lvalue % base >= 10)
			str[i + sig] = lvalue % base - 10 + 'A';
		lvalue = lvalue / base;
		i--;
	}
	if (sig == 1)
		str[0] = '-';
	return (str);
}
