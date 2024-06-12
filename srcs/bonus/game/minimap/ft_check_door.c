/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_door.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:31:20 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/10 16:30:01 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	is_door_at_position(t_cub *cub, int x, int y)
{
	if (y >= 0 && y < cub->map->map_height && x >= 0 \
	&& x < ft_strlen(cub->map->map[y]))
	{
		if (cub->map->map[y][x] == 'D' || cub->map->map[y][x] == 'd')
			return (1);
	}
	return (0);
}

static double	calculate_dot_product(double player_dir_x, \
double player_dir_y, double door_dir_x, double door_dir_y)
{
	double	player_dir_length;
	double	door_dir_length;

	door_dir_length = sqrt(door_dir_x * door_dir_x + door_dir_y * door_dir_y);
	player_dir_length = sqrt(player_dir_x * player_dir_x \
	+ player_dir_y * player_dir_y);
	player_dir_x /= player_dir_length;
	player_dir_y /= player_dir_length;
	door_dir_x /= door_dir_length;
	door_dir_y /= door_dir_length;
	return (player_dir_x * door_dir_x + player_dir_y * door_dir_y);
}

int	_is_door_near(t_cub *cub, int *xy, int *player_xy)
{
	double	player_dir_xy[2];
	double	door_dir_xy[2];
	double	dot_product;

	player_dir_xy[X] = cos(cub->map->player_angle);
	player_dir_xy[Y] = sin(cub->map->player_angle);
	door_dir_xy[X] = xy[X] - player_xy[X];
	door_dir_xy[Y] = xy[Y] - player_xy[Y];
	dot_product = calculate_dot_product(player_dir_xy[X], \
	player_dir_xy[Y], door_dir_xy[X], door_dir_xy[Y]);
	if (dot_product > 0.9)
	{
		if (cub->input[8] == 1 && !cub->pressed)
		{
			if (cub->map->map[xy[Y]][xy[X]] == 'D')
				cub->map->map[xy[Y]][xy[X]] = 'd';
			else if (cub->map->map[xy[Y]][xy[X]] == 'd')
				cub->map->map[xy[Y]][xy[X]] = 'D';
		}
		return (1);
	}
	return (0);
}

int	is_door_near(t_cub *cub)
{
	int		player_xy[2];
	int		xy[2];

	player_xy[X] = (int)cub->map->player_pos[X] / TILE_SIZE;
	player_xy[Y] = (int)cub->map->player_pos[Y] / TILE_SIZE;
	xy[Y] = player_xy[Y] - 1;
	while (xy[Y] <= player_xy[Y] + 1)
	{
		xy[X] = player_xy[X] - 1;
		while (xy[X] <= player_xy[X] + 1)
		{
			if (is_door_at_position(cub, xy[X], xy[Y]) && \
			_is_door_near(cub, xy, player_xy))
				return (1);
			xy[X]++;
		}
		xy[Y]++;
	}
	return (0);
}
