/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:11:41 by pcervill          #+#    #+#             */
/*   Updated: 2022/04/07 12:44:00 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num *= -1;
	}
	if (num < 10)
	{
		ft_putchar_fd((num + 48), fd);
		return ;
	}
	else
	{
		ft_putnbr_fd((num / 10), fd);
		ft_putnbr_fd((num % 10), fd);
	}
}
