/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 10:06:53 by exam              #+#    #+#             */
/*   Updated: 2018/01/09 19:41:26 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa_base(int value, int base)
{
	int		i;
	int		lenght;
	int		negative;
	long	lvalue;
	long	tmp_value;
	char	*str;

	lenght = 1;
	negative = 0;
	lvalue = value;
	if (base < 2)
		base = 2;
	else if (base > 16)
		base = 16;
	if (base == 10 && lvalue < 0)
		negative = 1;
	if (lvalue < 0)
		lvalue = -lvalue;
	tmp_value = lvalue;
	while (tmp_value / base > 0)
	{
		lenght++;
		tmp_value = tmp_value / base;
	}
	if (!(str = malloc(sizeof(char) * (lenght + negative + 1))))
		return (NULL);
	i = -1;
	while (++i < lenght + negative + 1)
		str[i] = 0;
	i--;
	while (i >= 0)
	{
		i--;
		if (lvalue % base > 9)
			str[i] = 'A' + lvalue % base - 10;
		else if (lvalue % base <= 9)
			str[i] = '0' + lvalue % base;
		lvalue = lvalue / base;
	}
	if (negative == 1)
		str[0] = '-';
	return (str);
}
