/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:55:21 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/10 14:56:32 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <math.h>

// 				-- WALL CHECKER --
// is_wall : will check is the current position
//			 is a wall.

int	is_wall(t_cub *cub, int x, int y)
{
	int	grid_x;
	int	grid_y;
	int	width;
	int	height;

	width = WIDTH;
	height = HEIGHT;
	grid_x = x / TILE_SIZE;
	grid_y = y / TILE_SIZE;
	if (grid_y >= 0 && grid_y < cub->map->map_height && \
	grid_x >= 0 && grid_x < ft_strlen(cub->map->map[grid_y]))
		return (cub->map->map[grid_y][grid_x] == '1');
	return (0);
}

// ---- CALCULATE WALL HEIGHT ----
// get_wall_height : This function calculates the height of
// the wall as a function of the distance from it
// HEIGHT = TILE SIZE / DISTANCE * DISTANCE PROJECTION PLANE
//
// double corrected_distance : distance * the cosinus of the angle
// difference to fix distortion caused by perspective projection
//
// double distance_to_projection_plane : give the 'size' of the walls line
// (cause wall is drawn line by line)
//
// @distances : Tab of [RAY_COUNT] double, containing every distances
// between the player and the walls (thanks to rays)

int	get_wall_height(t_cub *cub, double *distances, int x)
{
	double	corrected_distance;
	double	distance_to_projection_plane;

	corrected_distance = distances[x] * cos(cub->map->player_angle - \
					(cub->map->player_angle - (FOV / 2) + \
					(x * (FOV / WIDTH))));
	distance_to_projection_plane = (WIDTH / 2) / tan(FOV / 2);
	return ((TILE_SIZE / corrected_distance) * distance_to_projection_plane);
}
