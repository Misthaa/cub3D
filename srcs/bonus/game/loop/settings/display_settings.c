/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 00:19:43 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/10 16:54:00 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	display_resolution(t_cub *cub);
void	display_sensibility(t_cub *cub);

void	display_settings(t_cub *cub)
{
	mlx_clear_window(cub->mlx, cub->win);
	mlx_set_font(cub->mlx, cub->win, "assets/font/Pixellari.ttf");
	mlx_set_font_scale(cub->mlx, cub->win, "assets/font/Pixellari.ttf", 69.5f);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img[MENU], 0, 0);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img[S_BACK], 0, 0);
	display_resolution(cub);
	display_check_box(cub);
	display_sensibility(cub);
	ft_create_button_text(cub, (int [2]){cub->settings->width * 0.75f, \
	cub->settings->height * 0.92f}, apply_button);
	ft_create_button_text(cub, (int [2]){cub->settings->width * 0.10f, \
	cub->settings->height * 0.92f}, cancel_button);
}
