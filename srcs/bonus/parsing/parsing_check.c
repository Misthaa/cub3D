/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 22:09:41 by madegryc          #+#    #+#             */
/*   Updated: 2024/06/10 03:42:47 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// ---- COUNT LINE MAP ----
//	count_line_map : This function counts the number of lines in the map.
//  We need it to know the size of the map's malloc

int	count_line_map(t_cub *cub, int fd, char *line)
{
	char	*map;

	map = line;
	while (map)
	{
		if (map[0] == '1' || map[0] == ' ' || map[0] == '\n')
			cub->parse->count_line_map++;
		free(map);
		map = get_next_line(fd);
	}
	close(fd);
	return (1);
}

int	close_free_all(t_cub *cub, int fd, char *error)
{
	close(fd);
	return (ft_error(error, cub));
}

// ---- CHECK AFTER FILL ----
//	check_after_fill : This function checks if the map is valid.

int	check_after_fill(t_cub *cub, int fd, char *line)
{
	if (cub->parse->check != 6)
		return (close_free_all(cub, fd, \
		"Missing or bad information in the file\n"));
	if (put_map_struct(cub, fd, line) == 0)
		return (0);
	if (cub->parse->has_player != 1)
		return (free_map(cub, "No player in the map\n"));
	if (is_closed_map(cub->map->map) == 0)
		return (free_map(cub, "Invalid map\n"));
	close(fd);
	if (can_access_texture(cub) == 0)
		return (free_map(cub, NULL));
	if (cub->parse->check_floor > 1 || cub->parse->check_sky > 1)
		return (free_map(cub, "Double colors\n"));
	return (1);
}
