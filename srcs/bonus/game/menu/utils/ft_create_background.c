/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_background.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:49:26 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/09 13:53:37 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_create_background(t_cub *cub, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < cub->settings->height)
	{
		x = 0;
		while (x < cub->settings->width)
		{
			mlx_set_image_pixel(cub->mlx, cub->img[MENU], x, y, color);
			x++;
		}
		y++;
	}
}
