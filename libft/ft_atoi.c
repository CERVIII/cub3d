/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 22:59:20 by pcervill          #+#    #+#             */
/*   Updated: 2022/04/07 12:45:51 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	snumber(unsigned long int number, int sign)
{
	if (number > 2147483648 && sign == 1)
		number = 0;
	else if (number > 2147483647 && sign != 1)
		number = -1;
	return (number);
}

int	ft_atoi(const char *str)
{
	unsigned long int	number;
	int					sign;

	while ((*str == ' ') || (*str >= 7 && *str <= 13))
		str++;
	sign = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign++;
		str++;
	}
	number = 0;
	while (*str >= '0' && *str <= '9')
	{
		number = 10 * number + (*str - 48);
		str++;
	}
	number = snumber(number, sign);
	if (sign == 1)
		return (number * -1);
	return (number);
}
