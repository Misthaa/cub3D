/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:43:28 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/10 14:43:30 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// ---- COUNT COMMAS ----
//	count_commas : This function counts the number of commas in a string.

int	count_commas(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ',')
			j++;
		i++;
	}
	if (j != 2)
		return (0);
	return (1);
}

// ---- CHECK LAST COLOR ----
//	check_last_color : This function checks if the color has more than 3 values.

int	check_last_color(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			j++;
		i++;
	}
	if (j > 3)
		return (1);
	return (0);
}

// ---- CHECK IS ALPHA ----
//	check_is_alpha : This function checks if the string contains only numbers.

int	check_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	free_tab_error(char **line, char *error, t_cub *cub)
{
	ft_free_ctab(line);
	return (ft_error(error, cub));
}

int	free_map(t_cub *cub, char *error)
{
	ft_free_ctab(cub->map->map);
	if (error)
		return (ft_error(error, cub));
	return (0);
}
