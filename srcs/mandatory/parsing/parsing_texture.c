/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:54:29 by madegryc          #+#    #+#             */
/*   Updated: 2024/06/10 14:43:25 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_png_extension(char *file)
{
	int	i;

	i = ft_strlen(file) - 2;
	if ((file[i] != 'g' || file[i - 1] != 'n' \
		|| file[i - 2] != 'p' || file[i - 3] != '.'))
		return (ft_error("Invalid file extension in path\n", NULL));
	return (1);
}

// ---- CAN ACCESS TEXTURE ----
//	can_access_texture : This function checks if the path is valid.

int	can_access_texture(t_cub *cub)
{
	if (!cub->parse->no || access(cub->parse->no, F_OK) == -1 \
		|| access(cub->parse->no, R_OK) == -1)
		return (ft_error("Invalid path\n", cub));
	else if (!cub->parse->so || access(cub->parse->so, F_OK) == -1 \
		|| access(cub->parse->so, R_OK) == -1)
		return (ft_error("Invalid path\n", cub));
	else if (!cub->parse->we || access(cub->parse->we, F_OK) == -1 \
		|| access(cub->parse->we, R_OK) == -1)
		return (ft_error("Invalid path\n", cub));
	else if (!cub->parse->ea || access(cub->parse->ea, F_OK) == -1 \
		|| access(cub->parse->ea, R_OK) == -1)
		return (ft_error("Invalid path\n", cub));
	return (1);
}

// ---- CHECK IS EXTENSION ----
//	check_is_extension : This function checks if the path has an extension.

int	check_is_extension(t_cub *cub, char *line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '.')
			j++;
		i++;
	}
	if (j != 2)
		return (ft_error("Invalid path\n", cub));
	return (1);
}

// ---- PARSING TEXTURE ----
//	ft_parsing_texture : This function parses the texture in the file.

int	ft_parsing_texture(t_cub *cub, char *line)
{
	int		j;

	if (is_png_extension(line) == 0)
		return (0);
	if (check_is_extension(cub, line) == 0)
		return (0);
	j = 2;
	while (line[j] == ' ' || line[j] == '\t')
		j++;
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = 0;
	j += 2;
	if (line[0] == 'N' && cub->parse->no == NULL)
		cub->parse->no = ft_strdup(&line[j]);
	else if (line[0] == 'S' && cub->parse->so == NULL)
		cub->parse->so = ft_strdup(&line[j]);
	else if (line[0] == 'W' && cub->parse->we == NULL)
		cub->parse->we = ft_strdup(&line[j]);
	else if (line[0] == 'E' && cub->parse->ea == NULL)
		cub->parse->ea = ft_strdup(&line[j]);
	cub->parse->check++;
	return (1);
}
