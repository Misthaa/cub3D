/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:35:03 by madegryc          #+#    #+#             */
/*   Updated: 2024/06/10 16:46:00 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// ---IS_CUB_EXTENSION---
//	is_cub_extension : This function checks if the file has the right extension.

int	is_cub_extension(char *file)
{
	int	i;

	i = ft_strlen(file) - 1;
	if (file[i] != 'b' || file[i - 1] != 'u' \
		|| file[i - 2] != 'c' || file[i - 3] != '.')
		return (ft_error("Invalid file extension\n", NULL));
	return (1);
}

// ---- PARSING LINE ----
//	ft_parsing_line : This function parses the line in the file.
//	The function stop when it finds a "1" or a space to find the index of map.

int	ft_parsing_line(t_cub *cub, char *line)
{
	int	tmp;

	tmp = 0;
	if (line[0] == 'N' && line[1] == 'O')
		tmp = ft_parsing_texture(cub, line);
	else if (line[0] == 'S' && line[1] == 'O')
		tmp = ft_parsing_texture(cub, line);
	else if (line[0] == 'W' && line[1] == 'E')
		tmp = ft_parsing_texture(cub, line);
	else if (line[0] == 'E' && line[1] == 'A')
		tmp = ft_parsing_texture(cub, line);
	else if (line[0] == 'F' && line[1] == ' ')
		tmp = ft_parsing_color(cub, line, 1);
	else if (line[0] == 'C' && line[1] == ' ')
		tmp = ft_parsing_color(cub, line, 0);
	else
		return (ft_error("Invalid line in the file\n", cub));
	if (tmp == 0)
		return (0);
	return (1);
}

// ---- PUT MAP STRUCT ----
//	put_map_struct : This function puts the map in a struct.

int	put_map_struct(t_cub *cub, int fd, char *line)
{
	int		j;

	j = 0;
	cub->map->map = malloc(sizeof(char *) * (cub->parse->count_line_map + 2));
	if (!cub->map->map)
		return (ft_error("Malloc error\n", cub));
	line = get_next_line(fd);
	while (line && line[0] != '1' && line[0] != ' ')
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = 0;
		cub->map->map[j] = ft_parsing_map(cub, line);
		if (!cub->map->map[j])
			return (free_map(cub, "Invalid map\n"));
		j++;
		line = get_next_line(fd);
	}
	cub->map->map[j] = NULL;
	close (fd);
	return (1);
}

// ---- SKIP UNTIL MAP ----
//	skip_until_map : This function skips the lines until the map.
//  It's usefull for check the texture and color before the map.

char	*skip_until_map(t_cub *cub, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line && line[0] != '1' && line[0] != ' ')
	{
		if (line[0] != '\n')
		{
			if (ft_parsing_line(cub, line) == 0)
			{
				close(fd);
				free(line);
				get_next_line(-1);
				return (NULL);
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		close(fd);
	return (line);
}

// ---- PARSING MAP ----
//	ft_parsing_map : This function parses the map in the file.

int	ft_parsing(t_cub *cub, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_error("Invalid file\n", cub));
	if (is_cub_extension(file) == 0)
	{
		close(fd);
		return (ft_error("Invalid map\n", cub));
	}
	line = skip_until_map(cub, fd);
	if (!line)
		return (ft_error("Invalid map\n", cub));
	if (count_line_map(cub, fd, line) == 0)
		return (ft_error("Invalid map\n", cub));
	fd = open(file, O_RDONLY);
	if (check_after_fill(cub, fd, line) == 0)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
