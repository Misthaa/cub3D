/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slider_sensitivity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:59:06 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/10 03:21:49 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	change_sensibility(t_cub *cub, int sensi, char **sensibility, int which)
{
	cub->settings->n_sensibility = sensi;
	if (which == 0)
		*sensibility = "1";
	else if (which == 1)
		*sensibility = "2";
	else if (which == 2)
		*sensibility = "3";
	else if (which == 3)
		*sensibility = "4";
}

void	_put_sensibility(t_cub *cub, int sensi, char **sensibility, int *slider)
{
	system("paplay assets/sound/slider.ogg &");
	change_sensibility(cub, sensi, sensibility, sensi - 1);
	usleep(150000);
	*slider = sensi - 1;
}

// DEBUG Normed here, and created some lags in the slider.

void	put_sensibility(t_cub *cub, int *slider, char **sensibility)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(cub->mlx, &x, &y);
	if (y >= cub->settings->height * 0.23f && \
	y <= cub->settings->height * 0.35f)
	{
		if (x >= cub->settings->width * 0.35f && \
		x <= cub->settings->width * 0.40f && cub->mouse_left == 1)
			_put_sensibility(cub, 1, sensibility, slider);
		if (x >= cub->settings->width * 0.40f && \
		x <= cub->settings->width * 0.50f && cub->mouse_left == 1)
			_put_sensibility(cub, 2, sensibility, slider);
		if (x >= cub->settings->width * 0.50f && \
		x <= cub->settings->width * 0.55f && cub->mouse_left == 1)
			_put_sensibility(cub, 3, sensibility, slider);
		if (x >= cub->settings->width * 0.55f && \
		x <= cub->settings->width * 0.65f && cub->mouse_left == 1)
			_put_sensibility(cub, 4, sensibility, slider);
	}
}

void	display_sensibility(t_cub *cub)
{
	static int	slider_sensi = 0;
	static char	*sensibility = "undefined";

	mlx_string_put(cub->mlx, cub->win, cub->settings->width * 0.05, \
	cub->settings->height * 0.33f, 0xFFFFFFFF, "Sensibility");
	mlx_string_put(cub->mlx, cub->win, cub->settings->width * 0.70f, \
	cub->settings->height * 0.33f, 0xFFFFFFFF, sensibility);
	mlx_put_image_to_window(cub->mlx, cub->win, \
	cub->sprite->slider[slider_sensi], \
	cub->settings->width * 0.30f, cub->settings->height * 0.17f);
	put_sensibility(cub, &slider_sensi, &sensibility);
}
