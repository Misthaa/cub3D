/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:42:56 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/10 14:56:43 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// ---- PARSING MAP ----
//    ft_parsing_map : This function checks if the map is valid.
//	It also checks if the player is present and puts his position in the struct.

char	*ft_parsing_map(t_cub *cub, char *line)
{
	int			x;
	static int	y = 0;

	x = -1;
	while (line[++x])
	{
		if (line[x] == 'N' || line[x] == 'W' \
			|| line[x] == 'S' || line[x] == 'E')
		{
			cub->parse->has_player++;
			cub->map->player_pos[X] = x * TILE_SIZE + TILE_SIZE / 2;
			cub->map->player_pos[Y] = y * TILE_SIZE + TILE_SIZE / 2;
		}
		if (line[x] != '1' \
			&& line[x] != '0' && line[x] != 'N' \
			&& line[x] != 'S' && line[x] != 'W' && line[x] != 'E' \
			&& line[x] != '\n' && line[x] != ' ')
		{
			free(line);
			get_next_line(-1);
			return (NULL);
		}
	}
	y++;
	return (line);
}

// ---- CHECK LAST LINE ----
//    check_last_line : This function checks if the last line is valid.

int	check_last_line(char **str)
{
	int	j;

	j = -1;
	while (str[ft_tablen(str) - 1][++j])
	{
		if (str[ft_tablen(str) - 1][j] != '1' \
			&& str[ft_tablen(str) - 1][j] != ' ')
			return (0);
	}
	return (1);
}

// ---- CHECK FIRST LINE ----
//    check_first_line : This function checks if the first line is valid.

int	check_first_line(char **str)
{
	int	j;

	j = -1;
	while (str[0][++j])
	{
		if (str[0][j] != '1' && str[0][j] != ' ')
			return (0);
	}
	return (1);
}

// ---- CHECK SPACE OR VOID ----
//    check_space_or_void : This function checks if there 
//    is a space or a void around the player.

int	check_space_or_void(char **str, int i, int j)
{
	if (ft_strlen(str[i - 1]) < j || ft_strlen(str[i + 1]) < j)
		return (0);
	if (str[i][j - 1] == 0 || str[i][j + 1] == 0 \
		|| str[i - 1][j] == 0 || str[i + 1][j] == 0)
		return (0);
	if (str[i][j - 1] == ' ' || str[i][j + 1] == ' ' \
		|| str[i - 1][j] == ' ' || str[i + 1][j] == ' ')
		return (0);
	return (1);
}

// ---- IS CLOSED MAP ----
//    is_closed_map : This function checks if the map is closed.

int	is_closed_map(char **str)
{
	int		i;
	int		j;

	if (!check_first_line(str))
		return (0);
	if (!check_last_line(str))
		return (0);
	i = -1;
	while (str[++i])
	{
		j = 0;
		if (str[i][j] != '1' && str[i][j] != ' ')
			return (0);
		while (str[i][++j])
		{
			if (str[i][j] == '0' || str[i][j] == 'N' || str[i][j] == 'S' \
				|| str[i][j] == 'W' || str[i][j] == 'E')
				if (check_space_or_void(str, i, j) == 0)
					return (0);
		}
	}
	return (1);
}
