/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 02:00:58 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/09 13:53:37 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

// 				   --- PUT PIXEL ---
// ft_put_pixel : This function will draw the pixel 
//				 at x and y position with a specific color

void	ft_put_pixel(t_cub *cub, int color, int x, int y)
{
	mlx_set_image_pixel(cub->mlx, cub->img[MINIMAP], \
	cub->map->position[X] + x, cub->map->position[Y] + y, color);
}
