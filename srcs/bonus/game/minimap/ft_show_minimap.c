/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:17:49 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/10 16:51:12 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <math.h>

int		ft_get_color(int c);
void	ft_draw_tile(t_cub *cub, int pos[2], int color);
int		is_door_near(t_cub *cub);

void	_ft_draw_player(t_cub *cub, int *point_xy)
{
	int	i;
	int	j;

	i = point_xy[X] - 1;
	while (i <= point_xy[X] + 1)
	{
		j = point_xy[Y] - 1;
		while (j <= point_xy[Y] + 1)
		{
			mlx_set_image_pixel(cub->mlx, cub->img[MINIMAP], i, j, 0xFF000000);
			j++;
		}
		i++;
	}
}

void	ft_draw_player(t_cub *cub, int pos[2], int color)
{
	int		xy[2];
	int		point_xy[2];
	int		player_angle;
	int		radius;
	double	map_angle;

	radius = PLAYER_SIZE_MINIMAP;
	player_angle = cub->map->player_angle;
	map_angle = player_angle + PI / 2;
	xy[X] = pos[0] - radius;
	point_xy[X] = pos[0] + (int)(1.5 * radius * sin(map_angle));
	point_xy[Y] = pos[1] - (int)(1.5 * radius * cos(map_angle));
	while (xy[X] <= pos[0] + radius)
	{
		xy[Y] = pos[1] - radius - 1;
		while (++xy[Y] <= pos[1] + radius)
		{
			if ((xy[X] - pos[0]) * (xy[X] - pos[0]) + (xy[Y] - pos[1]) * \
			(xy[Y] - pos[1]) <= radius * radius)
				mlx_set_image_pixel(cub->mlx, cub->img[MINIMAP], \
				xy[X], xy[Y], color);
		}
		xy[X]++;
	}
	_ft_draw_player(cub, point_xy);
}

void	ft_create_map(t_cub *cub, int *start, int *end, int *tile_pos)
{
	int	x;
	int	y;

	y = start[Y];
	while (y <= end[Y])
	{
		x = start[X];
		while (x <= end[X])
		{
			if (y >= 0 && y < cub->map->map_height && \
			x >= 0 && x < ft_strlen(cub->map->map[y]))
			{
				tile_pos[X] = MARGIN_X + (x - start[X]) * (TILE_SIZE);
				tile_pos[Y] = MARGIN_Y + (y - start[Y]) * (TILE_SIZE);
				ft_draw_tile(cub, tile_pos, ft_get_color(cub->map->map[y][x]));
			}
			x++;
		}
		y++;
	}
}

void	draw_cardinal_points(t_cub *cub)
{
	if (cub->settings->d_cardinal)
	{
		mlx_string_put(cub->mlx, cub->win, 124, \
		45, 0xFFFFFFFF, "N");
		mlx_string_put(cub->mlx, cub->win, 227, \
		135, 0xFFFFFFFF, "E");
		mlx_string_put(cub->mlx, cub->win, 25, \
		135, 0xFFFFFFFF, "W");
		mlx_string_put(cub->mlx, cub->win, 124, \
		234, 0xFFFFFFFF, "S");
	}
}

void	ft_show_minimap(t_cub *cub)
{
	int	map_center[2];
	int	start[2];
	int	end[2];
	int	tile_pos[2];
	int	player_screen_pos[2];

	map_center[X] = cub->map->player_pos[X] / TILE_SIZE;
	map_center[Y] = cub->map->player_pos[Y] / TILE_SIZE;
	start[X] = map_center[X] - MINIMAP_WIDTH / 2;
	start[Y] = map_center[Y] - MINIMAP_HEIGHT / 2;
	end[X] = map_center[X] + MINIMAP_WIDTH / 2;
	end[Y] = map_center[Y] + MINIMAP_HEIGHT / 2;
	ft_create_map(cub, start, end, tile_pos);
	player_screen_pos[X] = MARGIN_X + (MINIMAP_WIDTH * (TILE_SIZE)) / 2;
	player_screen_pos[Y] = MARGIN_Y + (MINIMAP_HEIGHT * (TILE_SIZE)) / 2;
	ft_draw_player(cub, player_screen_pos, 0xFFFFFFFF);
	is_door_near(cub);
	mlx_set_font(cub->mlx, cub->win, "assets/font/Pixellari.ttf");
	mlx_set_font_scale(cub->mlx, cub->win, "assets/font/Pixellari.ttf", 20.5f);
	draw_cardinal_points(cub);
}
