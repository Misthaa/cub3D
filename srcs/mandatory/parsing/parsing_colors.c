/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:42:50 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/10 15:42:22 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// --- CONVERT RGB TO INT ---
//	ft_convert_rbg_to_int : This function converts the RGB color to an int.
//	We add 255 << 24 to have the alpha channel at 255 (Macro issue).

int	ft_convert_rbg_to_int(char **line)
{
	return (ft_atoi(line[0]) << 16 | ft_atoi(line[1]) << 8 \
	| ft_atoi(line[2]) | 255 << 24);
}

// ---- PUT TO STRUCT COLORS ----
//	put_to_struct_colors : This function puts the colors in the struct.

void	put_to_struct_colors(t_cub *cub, char **line_colors, int boolean)
{
	cub->parse->check++;
	if (boolean == 1)
	{
		cub->parse->check_floor++;
		cub->parse->floor_color = ft_convert_rbg_to_int(line_colors);
	}
	else
	{
		cub->parse->check_sky++;
		cub->parse->sky_color = ft_convert_rbg_to_int(line_colors);
	}
	ft_free_ctab(line_colors);
}

int	ft_check_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	_ft_parsing_color(t_cub *cub, int boolean, char **line_colors)
{
	int		color;
	int		i;

	i = -1;
	while (line_colors[++i])
	{
		if (check_is_alpha(line_colors[i]) == 1)
			return (free_tab_error(line_colors, \
			"Invalid color (Alpha)\n", cub));
		if (!ft_check_number(line_colors[i]))
			return (free_tab_error(line_colors, \
			"Invalid color (Alpha)\n", cub));
		color = ft_atoi(line_colors[i]);
		if (color < 0 || color > 255)
			return (free_tab_error(line_colors, \
			"Invalid color (Value)\n", cub));
	}
	put_to_struct_colors(cub, line_colors, boolean);
	return (1);
}

// ---- PARSING COLOR ----
//	ft_parsing_color : This function parses the color in the file.

int	ft_parsing_color(t_cub *cub, char *line, int boolean)
{
	char	**line_colors;

	if (count_commas(line) == 0)
		return (ft_error("Invalid color (Commas)\n", cub));
	line += 2;
	line_colors = ft_split(line, ',');
	if (line_colors == NULL)
		return (ft_error("Malloc error\n", cub));
	if (ft_tablen(line_colors) != 3)
		return (free_tab_error(line_colors, "Invalid color (Values)\n", cub));
	if (line_colors == NULL)
		return (ft_error("Malloc error\n", cub));
	if (check_last_color(*line_colors) == 1)
		return (free_tab_error(line_colors, \
		"Invalid color (Too many values)\n", cub));
	return (_ft_parsing_color(cub, boolean, line_colors));
}
