/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:41:30 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/10 03:09:24 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	_get_player_angle(t_cub *cub)
{
	if (cub->player_start_angle == 'N')
		cub->map->player_angle = 4.7f;
	if (cub->player_start_angle == 'E')
		cub->map->player_angle = 0.2f;
	if (cub->player_start_angle == 'S')
		cub->map->player_angle = 1.7f;
	if (cub->player_start_angle == 'W')
		cub->map->player_angle = 3.2f;
}

void	get_player_angle(t_cub *cub)
{
	int		x;
	int		y;
	int		founded;
	char	**map;

	y = -1;
	founded = 0;
	map = cub->map->map;
	while (map[++y] && !founded)
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'E' || \
				map[y][x] == 'W' || map[y][x] == 'S')
			{
				cub->player_start_angle = map[y][x];
				founded = 1;
				break ;
			}
		}
	}
	if (founded)
		_get_player_angle(cub);
}

int	get_map_height(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->map->map[i])
		i++;
	return (i);
}
