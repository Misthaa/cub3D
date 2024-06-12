/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slider_res.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:59:06 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/10 03:21:42 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	_put_res(t_cub *cub, int size[2], char **res, int *slider)
{
	system("paplay assets/sound/slider.ogg &");
	cub->settings->n_width = size[0];
	cub->settings->n_height = size[1];
	usleep(150000);
	if (size[0] == 1280)
	{
		*res = "1280x900";
		*slider = 0;
	}
	else if (size[0] == 1440)
	{
		*res = "1440x900";
		*slider = 1;
	}
	else if (size[0] == 1600)
	{
		*res = "1600x900";
		*slider = 2;
	}
	else if (size[0] == 1920)
	{
		*res = "1900x900";
		*slider = 3;
	}
}

void	put_res(t_cub *cub, int *slider, char **res)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(cub->mlx, &x, &y);
	if (y >= cub->settings->height * 0.1f && \
	y <= cub->settings->height * 0.18f)
	{
		if (x >= cub->settings->width * 0.35f && \
		x <= cub->settings->width * 0.40f && cub->mouse_left == 1)
			_put_res(cub, (int [2]){1280, 900}, res, slider);
		if (x >= cub->settings->width * 0.40f && \
		x <= cub->settings->width * 0.50f && cub->mouse_left == 1)
			_put_res(cub, (int [2]){1440, 900}, res, slider);
		if (x >= cub->settings->width * 0.50f && \
		x <= cub->settings->width * 0.55f && cub->mouse_left == 1)
			_put_res(cub, (int [2]){1600, 900}, res, slider);
		if (x >= cub->settings->width * 0.55f && \
		x <= cub->settings->width * 0.65f && cub->mouse_left == 1)
			_put_res(cub, (int [2]){1920, 900}, res, slider);
	}
}

void	find_first_res(t_cub *cub, int *slider_res, char **res)
{
	if (cub->settings->width == 1920)
	{
		*slider_res = 3;
		*res = "1920x900";
	}
	else if (cub->settings->width == 1600)
	{
		*slider_res = 2;
		*res = "1600x900";
	}
	else if (cub->settings->width == 1440)
	{
		*slider_res = 1;
		*res = "1440x900";
	}
	else if (cub->settings->width == 1280)
	{
		*slider_res = 0;
		*res = "1280x900";
	}
}

void	display_resolution(t_cub *cub)
{
	static int	first = 0;
	static int	slider_res = 0;
	static char	*res = "undefined";

	if (!first)
	{
		find_first_res(cub, &slider_res, &res);
		first = 1;
	}
	mlx_string_put(cub->mlx, cub->win, cub->settings->width * 0.05f, \
	cub->settings->height * 0.16f, 0xFFFFFFFF, "Resolution");
	mlx_string_put(cub->mlx, cub->win, cub->settings->width * 0.70f, \
	cub->settings->height * 0.16f, 0xFFFFFFFF, res);
	mlx_put_image_to_window(cub->mlx, cub->win, \
	cub->sprite->slider[slider_res], \
	cub->settings->width * 0.30f, cub->settings->height * 0.01f);
	put_res(cub, &slider_res, &res);
}
