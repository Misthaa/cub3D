/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_last_letter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 02:33:34 by ehalliez          #+#    #+#             */
/*   Updated: 2024/03/02 02:36:57 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_last(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	if (str[i - 1])
		return (str[i - 1]);
	return (0);
}
