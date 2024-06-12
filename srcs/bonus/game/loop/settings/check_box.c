/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_box.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 20:23:51 by madegryc          #+#    #+#             */
/*   Updated: 2024/06/10 16:53:31 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	_put_box(t_cub *cub, int y)
{
	int	just_clicked;

	just_clicked = cub->mouse_left;
	if (y >= cub->settings->height * 0.46f && \
	y <= cub->settings->height * 0.52f && cub->mouse_left == 1)
	{
		cub->settings->d_fps = !cub->settings->d_fps;
		system("paplay assets/sound/checkbox.ogg &");
	}
	if (y >= cub->settings->height * 0.55f && \
	y <= cub->settings->height * 0.62f && cub->mouse_left == 1)
	{
		cub->settings->d_date = !cub->settings->d_date;
		system("paplay assets/sound/checkbox.ogg &");
	}
	if (y >= cub->settings->height * 0.63f && \
	y <= cub->settings->height * 0.70f && cub->mouse_left == 1)
	{
		cub->settings->d_cardinal = !cub->settings->d_cardinal;
		system("paplay assets/sound/checkbox.ogg &");
	}
	if (just_clicked == 1)
		usleep(150000);
}

void	put_box(t_cub *cub)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(cub->mlx, &x, &y);
	if (x >= cub->settings->width * 0.46f && \
	x <= cub->settings->width * 0.5f)
	{
		_put_box(cub, y);
	}
}

void	display_check_box(t_cub *cub)
{
	mlx_string_put(cub->mlx, cub->win, cub->settings->width * 0.05f, \
	cub->settings->height * 0.50f, TEXT_COLOR, "Display FPS");
	mlx_string_put(cub->mlx, cub->win, cub->settings->width * 0.05f, \
	cub->settings->height * 0.60f, TEXT_COLOR, "Display Date");
	mlx_string_put(cub->mlx, cub->win, cub->settings->width * 0.05f, \
	cub->settings->height * 0.70f, TEXT_COLOR, "Display Cardinal");
	if (cub->settings->d_fps)
		mlx_put_image_to_window(cub->mlx, cub->win, cub->img[CHECKED], \
		cub->settings->width * 0.45f, cub->settings->height * 0.42f);
	else
		mlx_put_image_to_window(cub->mlx, cub->win, cub->img[UNCHECKED], \
		cub->settings->width * 0.45f, cub->settings->height * 0.42f);
	if (cub->settings->d_date)
		mlx_put_image_to_window(cub->mlx, cub->win, cub->img[CHECKED], \
		cub->settings->width * 0.45f, cub->settings->height * 0.52f);
	else
		mlx_put_image_to_window(cub->mlx, cub->win, cub->img[UNCHECKED], \
		cub->settings->width * 0.45f, cub->settings->height * 0.52f);
	if (cub->settings->d_cardinal)
		mlx_put_image_to_window(cub->mlx, cub->win, cub->img[CHECKED], \
		cub->settings->width * 0.45f, cub->settings->height * 0.62f);
	else
		mlx_put_image_to_window(cub->mlx, cub->win, cub->img[UNCHECKED], \
		cub->settings->width * 0.45f, cub->settings->height * 0.62f);
	put_box(cub);
}
