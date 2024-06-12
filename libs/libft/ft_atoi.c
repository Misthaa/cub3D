/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:19:38 by ehalliez          #+#    #+#             */
/*   Updated: 2023/11/07 16:29:55 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	result_atoi(int i, int neg, int pos, char *nb)
{
	int	number;

	number = 0;
	while (nb[i] >= '0' && nb[i] <= '9')
	{
		number = number * 10 + nb[i] - '0';
		i++;
	}
	if (neg > 0 && pos > 0)
		return (0);
	if (neg == 1)
		return (-number);
	if (pos == 1)
		return (number);
	if (pos == 0 && neg == 0)
		return (number);
	return (0);
}

int	ft_atoi(const char *nb)
{
	int	i;
	int	number;
	int	neg;
	int	pos;

	i = 0;
	neg = 0;
	pos = 0;
	while ((nb[i] >= 7 && nb[i] <= 13) || nb[i] == ' ')
		i++;
	while (nb[i] == '-' || nb[i] == '+')
	{
		if (nb[i] == '-')
			neg++;
		if (nb[i] == '+')
			pos++;
		i++;
	}
	number = result_atoi(i, neg, pos, (char *)nb);
	return (number);
}
