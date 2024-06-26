/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 00:10:44 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/10 02:38:31 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// -- SHOW BASE --
// ft_show_base : This function will display on half of the screen
//				  (cut by the X axis), and put pixels of different
//				  colors for the "ceiling" and the ground/floor.

void	ft_show_base(t_cub *cub)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				mlx_set_image_pixel(cub->mlx, cub->img[BASE], \
				x, y, cub->parse->sky_color);
			else
				mlx_set_image_pixel(cub->mlx, cub->img[BASE], \
				x, y, cub->parse->floor_color);
			x++;
		}
		y++;
	}
}
