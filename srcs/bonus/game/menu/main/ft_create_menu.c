/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_menu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:47:30 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/09 13:53:37 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_create_menu(t_cub *cub)
{
	int				width;
	int				height;
	static double	i = 0;

	width = cub->settings->width;
	height = cub->settings->height;
	if (i < 1)
		mlx_put_image_to_window(cub->mlx, cub->win, cub->img[M_BACK], -100, 0);
	else if (i > 1)
	{
		mlx_put_image_to_window(cub->mlx, cub->win, \
		cub->img[M_BACK_2], -100, 0);
		if (i >= 2)
			i = 0;
	}
	ft_create_button(cub, (int [2]){width * 0.10f, \
	height * 0.40f}, play_button, 1);
	ft_create_button(cub, (int [2]){width * 0.10f, \
	height * 0.60f}, settings_button, 2);
	ft_create_button(cub, (int [2]){width * 0.10f, \
	height * 0.80f}, quit_button, 3);
	i += 0.03;
}
