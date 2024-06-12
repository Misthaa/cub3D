/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_ttab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 01:29:34 by ehalliez          #+#    #+#             */
/*   Updated: 2024/03/01 13:09:03 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_free_ttab(char ***cmd_args)
{
	int	i;

	i = 0;
	while (cmd_args[i])
	{
		ft_free_ctab(cmd_args[i]);
		i++;
	}
	free(cmd_args);
	return (1);
}
