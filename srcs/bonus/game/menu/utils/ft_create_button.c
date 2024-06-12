/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_button.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:46:21 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/09 13:53:37 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_create_button_text(t_cub *cub, int pos[2], char *(*f)(void *, int))
{
	int	x_hover;
	int	y_hover;
	int	x;
	int	y;

	x_hover = pos[0] + 150;
	y_hover = pos[1];
	mlx_mouse_get_pos(cub->mlx, &x, &y);
	if (x >= x_hover - HOVER_WIDTH / 2 && x <= x_hover + HOVER_WIDTH / 2 && \
		y >= y_hover - HOVER_HEIGHT / 2 - 20 && y <= y_hover + HOVER_HEIGHT / 2)
	{
		if (cub->mouse_left == true)
			f(cub, 1);
	}
	mlx_string_put(cub->mlx, cub->win, pos[0], pos[1], TEXT_COLOR, f(cub, 0));
}

void	ft_first_choice(t_cub *cub, int *xy, \
int *xy_hover, char *(*f)(void *, int))
{
	if (xy[X] >= xy_hover[X] - HOVER_WIDTH / 2 && \
	xy[X] <= xy_hover[X] + HOVER_WIDTH / 2 && \
		xy[Y] >= xy_hover[Y] - HOVER_HEIGHT / 2 - 20 \
		&& xy[Y] <= xy_hover[Y] + HOVER_HEIGHT / 2)
	{
		mlx_put_image_to_window(cub->mlx, cub->win, \
		cub->sprite->button[1], -400, -30);
		if (cub->mouse_left == true)
			f(cub, 1);
	}
}

void	ft_second_choice(t_cub *cub, int *xy, \
int *xy_hover, char *(*f)(void *, int))
{
	if (xy[X] >= xy_hover[X] - HOVER_WIDTH / 2 && \
	xy[X] <= xy_hover[X] + HOVER_WIDTH / 2 && \
	xy[Y] >= xy_hover[Y] - HOVER_HEIGHT / 2 - 20 && \
	xy[Y] <= xy_hover[Y] + HOVER_HEIGHT / 2)
	{
		mlx_put_image_to_window(cub->mlx, cub->win, \
		cub->sprite->button[3], -270, xy[2] * 0.20f);
		if (cub->mouse_left == true)
			f(cub, 1);
	}
}

void	ft_third_choice(t_cub *cub, int *xy, \
int *xy_hover, char *(*f)(void *, int))
{
	if (xy[X] >= xy_hover[X] - HOVER_WIDTH / 2 && \
	xy[X] <= xy_hover[X] + HOVER_WIDTH / 2 && \
		xy[Y] >= xy_hover[Y] - HOVER_HEIGHT / 2 - 20 && \
		xy[Y] <= xy_hover[Y] + HOVER_HEIGHT / 2)
	{
		mlx_put_image_to_window(cub->mlx, cub->win, \
		cub->sprite->button[5], -400, xy[2] * 0.40f);
		if (cub->mouse_left == true)
			f(cub, 1);
	}
}

void	ft_create_button(t_cub *cub, int pos[2], \
char *(*f)(void *, int), int choice)
{
	int	x_hover;
	int	y_hover;
	int	x;
	int	y;
	int	height;

	x_hover = pos[0] + 150;
	y_hover = pos[1] - 16;
	height = cub->settings->height;
	mlx_mouse_get_pos(cub->mlx, &x, &y);
	mlx_put_image_to_window(cub->mlx, cub->win, \
	cub->sprite->button[0], -400, -30);
	if (choice == 1)
		ft_first_choice(cub, (int [2]){x, y}, (int [2]){x_hover, y_hover}, f);
	mlx_put_image_to_window(cub->mlx, cub->win, \
	cub->sprite->button[2], -270, height * 0.20f);
	if (choice == 2)
		ft_second_choice(cub, (int [3]){x, y, height}, \
		(int [2]){x_hover, y_hover}, f);
	mlx_put_image_to_window(cub->mlx, cub->win, \
	cub->sprite->button[4], -400, height * 0.40f);
	if (choice == 3)
		ft_third_choice(cub, (int [3]){x, y, height}, \
		(int [2]){x_hover, y_hover}, f);
}
