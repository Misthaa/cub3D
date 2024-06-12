/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_minimap_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:40:05 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/10 01:07:10 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_get_color(int c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (GROUND_COLOR);
	else if (c == '1')
		return (WALL_COLOR);
	else if (c == 'D')
		return (0xCCE8B11A);
	else if (c == 'd')
		return (0xCC6A5ACD);
	else
		return (0x00FFFFFF);
}

void	ft_draw_tile(t_cub *cub, int pos[2], int color)
{
	int	x;
	int	y;
	int	size;

	size = TILE_SIZE;
	if (!color)
		return ;
	x = pos[0];
	while (x < pos[0] + size)
	{
		y = pos[1];
		while (y < pos[1] + size)
		{
			mlx_set_image_pixel(cub->mlx, cub->img[MINIMAP], x, y, color);
			y++;
		}
		x++;
	}
}
