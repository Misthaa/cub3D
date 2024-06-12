/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:24:53 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/10 15:21:46 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// ---- DRAW WALLS ----
// ft_draw_walls : This function will draw every walls in 3D.
// After calculating the height of the wall
// we calculate the start position of the Y with the size of the wall

void	case_two(t_cub *cub, int xy[2], int start, int wall_height)
{
	int		tex_xy[2];
	int		map_xy[2];
	int		texture_index;
	int		texture_color;
	char	wall_character;

	texture_index = cub->map->ray_orientation[xy[X]];
	tex_xy[X] = (fmod(cub->map->x_ray[xy[X]], TILE_SIZE) / TILE_SIZE) \
	* cub->sprite->wall[texture_index]->width;
	tex_xy[Y] = ((xy[Y] - start) * cub->sprite->wall[texture_index]->height) \
	/ wall_height;
	texture_color = mlx_get_image_pixel(cub->mlx, \
		cub->sprite->wall[texture_index]->texture, tex_xy[X], tex_xy[Y]);
	map_xy[X] = (int)cub->map->x_ray[xy[X]];
	map_xy[Y] = (int)cub->map->y_ray[xy[X]];
	wall_character = cub->map->map[map_xy[Y] \
	/ TILE_SIZE][map_xy[X] / TILE_SIZE];
	texture_color = mlx_get_image_pixel(cub->mlx, cub->sprite->wall \
	[cub->map->ray_orientation[xy[X]]]->texture, tex_xy[X], tex_xy[Y]);
	if (wall_character == 'D')
		texture_color = mlx_get_image_pixel(cub->mlx, \
		cub->sprite->wall[4]->texture, tex_xy[X], tex_xy[Y]);
	mlx_set_image_pixel(cub->mlx, cub->img[BASE], xy[X], xy[Y], texture_color);
}

void	_case_one(t_cub *cub, int *tex_xy, int *xy, int *start_and_wall_height)
{
	char	wall_character;
	int		texture_color;
	int		map_x;
	int		map_y;

	tex_xy[X] = (tex_xy[X] * cub->sprite->wall \
	[cub->map->ray_orientation[xy[X]]]->width) / TILE_SIZE;
	tex_xy[Y] = ((xy[Y] - start_and_wall_height[0]) * cub->sprite->wall \
	[cub->map->ray_orientation[xy[X]]]->height) / start_and_wall_height[1];
	map_x = (int)cub->map->x_ray[xy[X]];
	map_y = (int)cub->map->y_ray[xy[X]];
	wall_character = cub->map->map[map_y / TILE_SIZE][map_x / TILE_SIZE];
	texture_color = mlx_get_image_pixel(cub->mlx, cub->sprite->wall \
	[cub->map->ray_orientation[xy[X]]]->texture, tex_xy[X], tex_xy[Y]);
	if (wall_character == 'D')
		texture_color = mlx_get_image_pixel(cub->mlx, \
		cub->sprite->wall[4]->texture, tex_xy[X], tex_xy[Y]);
	mlx_set_image_pixel(cub->mlx, cub->img[BASE], xy[X], xy[Y], texture_color);
}

void	case_one(t_cub *cub, int xy[2], int start, int wall_height)
{
	int		tex_xy[2];
	double	wall_angle;
	double	angle_diff;

	wall_angle = atan2(cub->map->y_ray[xy[X]] - \
	cub->map->player_pos[Y], cub->map->x_ray[xy[X]] - cub->map->player_pos[X]);
	angle_diff = fmod(wall_angle - cub->map->player_angle + 2 * PI, 2 * PI);
	if (angle_diff > PI)
		angle_diff -= 2 * PI;
	if (angle_diff < -PI)
		angle_diff += 2 * PI;
	if (fabs(angle_diff) < PI / 4 || fabs(angle_diff) > 3 * PI / 4)
	{
		tex_xy[X] = (int)cub->map->y_ray[xy[X]] % TILE_SIZE;
		tex_xy[Y] = ((xy[Y] - start) * cub->sprite->wall \
		[cub->map->ray_orientation[xy[X]]]->height) / wall_height;
	}
	else
	{
		tex_xy[X] = (int)cub->map->x_ray[xy[X]] % TILE_SIZE;
		tex_xy[Y] = ((int)cub->map->x_ray[xy[X]] % TILE_SIZE) * \
		cub->sprite->wall[cub->map->ray_orientation[xy[X]]]->height / TILE_SIZE;
	}
	_case_one(cub, tex_xy, xy, (int [2]){start, wall_height});
}

void	ft_draw_walls(t_cub *cub, double *distances)
{
	int	x;
	int	y;
	int	wall_height;
	int	start;
	int	end;

	x = 0;
	while (x < cub->settings->width)
	{
		wall_height = get_wall_height(cub, distances, x);
		start = (cub->settings->height / 2) - (wall_height / 2);
		end = start + wall_height;
		y = start;
		if (y < 0)
			y = 0;
		while (y < end && y < cub->settings->height)
		{
			if (cub->map->ray_side[x] == 0)
				case_one(cub, (int [2]){x, y}, start, wall_height);
			else
				case_two(cub, (int [2]){x, y}, start, wall_height);
			y++;
		}
		x++;
	}
}
