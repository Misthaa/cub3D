/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:13:22 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/10 02:38:21 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <math.h>

// 				   --- Send rays ---
// ft_put_rays : This function will send every position of the
//				 rays for i < RAY_COUNT

void	find_dist(t_rays *rays)
{
	if (rays->ray_dir[X] < 0)
	{
		rays->step_xy[X] = -1;
		rays->side_dist_xy[X] = (rays->xy[X] - rays->map_xy[X]) * \
		rays->delta_dist_xy[X];
	}
	else
	{
		rays->step_xy[X] = 1;
		rays->side_dist_xy[X] = (rays->map_xy[X] + 1.0 - rays->xy[X]) * \
		rays->delta_dist_xy[X];
	}
	if (rays->ray_dir[Y] < 0)
	{
		rays->step_xy[Y] = -1;
		rays->side_dist_xy[Y] = (rays->xy[Y] - rays->map_xy[Y]) * \
		rays->delta_dist_xy[Y];
	}
	else
	{
		rays->step_xy[Y] = 1;
		rays->side_dist_xy[Y] = (rays->map_xy[Y] + 1.0 - rays->xy[Y]) * \
		rays->delta_dist_xy[Y];
	}
}

void	trace_until_wall(t_cub *cub, t_rays *rays)
{
	while (!is_wall(cub, rays->map_xy[X], rays->map_xy[Y]))
	{
		if (rays->side_dist_xy[X] < rays->side_dist_xy[Y])
		{
			rays->side_dist_xy[X] += rays->delta_dist_xy[X];
			rays->map_xy[X] += rays->step_xy[X];
			rays->side = 0;
		}
		else
		{
			rays->side_dist_xy[Y] += rays->delta_dist_xy[Y];
			rays->map_xy[Y] += rays->step_xy[Y];
			rays->side = 1;
		}
	}
}

void	get_orientation(t_cub *cub, t_rays *rays, int i)
{
	if (rays->side == 0)
		rays->perp_wall_dist = (rays->map_xy[X] - rays->xy[X] + \
		(1 - rays->step_xy[X]) / 2) / rays->ray_dir[X];
	else
		rays->perp_wall_dist = (rays->map_xy[Y] - rays->xy[Y] + \
		(1 - rays->step_xy[Y]) / 2) / rays->ray_dir[Y];
	cub->map->distances[i] = rays->perp_wall_dist;
	cub->map->x_ray[i] = rays->xy[X] + rays->perp_wall_dist * rays->ray_dir[X];
	cub->map->y_ray[i] = rays->xy[Y] + rays->perp_wall_dist * rays->ray_dir[Y];
	cub->map->ray_side[i] = rays->side;
	if (rays->side == 0)
	{
		if (rays->ray_dir[X] > 0)
			cub->map->ray_orientation[i] = WEST;
		else
			cub->map->ray_orientation[i] = EAST;
	}
	else
	{
		if (rays->ray_dir[Y] > 0)
			cub->map->ray_orientation[i] = NORTH;
		else
			cub->map->ray_orientation[i] = SOUTH;
	}
}

void	_ft_put_rays(t_cub *cub, float angle, int i)
{
	t_rays	*rays;

	rays = &cub->map->rays;
	rays->ray_dir[X] = cosf(angle);
	rays->ray_dir[Y] = sinf(angle);
	rays->xy[X] = cub->map->player_pos[X];
	rays->xy[Y] = cub->map->player_pos[Y];
	rays->delta_dist_xy[X] = fabs(1 / rays->ray_dir[X]);
	rays->delta_dist_xy[Y] = fabs(1 / rays->ray_dir[Y]);
	rays->map_xy[X] = (int)rays->xy[X];
	rays->map_xy[Y] = (int)rays->xy[Y];
	find_dist(rays);
	trace_until_wall(cub, rays);
	get_orientation(cub, rays, i);
}

void	ft_put_rays(t_cub *cub)
{
	float	angle;
	float	angle_step;
	int		i;

	angle_step = FOV / WIDTH;
	angle = cub->map->player_angle - (FOV / 2);
	i = 0;
	while (i < WIDTH)
	{
		_ft_put_rays(cub, angle, i);
		angle += angle_step;
		i++;
	}
}
