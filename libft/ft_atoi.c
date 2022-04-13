/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:39:48 by nnorazma          #+#    #+#             */
/*   Updated: 2022/04/12 10:39:49 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\r'
		|| *nptr == '\n' || *nptr == '\f' || *nptr == '\v')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while ((*nptr >= '0' && *nptr <= '9') && *nptr != '\0')
	{
		res *= 10;
		res += *nptr - '0';
		nptr++;
	}
	return (res * sign);
}
