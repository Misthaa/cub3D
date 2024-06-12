/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:28:50 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/10 01:06:16 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	center_mouse(t_cub *cub, int *x, int *y)
{
	mlx_mouse_get_pos(cub->mlx, x, y);
	mlx_mouse_move(cub->mlx, cub->win, WIDTH / 2, HEIGHT / 2);
	mlx_mouse_hide();
}

void	ft_move_key(t_cub *cub)
{
	if (cub->input[FORWARD])
		ft_move_player(cub, FORWARD);
	if (cub->input[BACKWARD])
		ft_move_player(cub, BACKWARD);
	if (cub->input[LEFT])
		ft_move_player(cub, LEFT);
	if (cub->input[RIGHT])
		ft_move_player(cub, RIGHT);
}

void	ft_rotate_key(t_cub *cub, int x)
{
	if (cub->input[ARROW_RIGHT])
		cub->map->player_angle += 0.05;
	if (cub->input[ARROW_LEFT])
		cub->map->player_angle -= 0.05;
	if (cub->input[ARROW_RIGHT] || x > WIDTH / 2)
		cub->map->player_angle += cub->settings->sensibility;
	if (cub->input[ARROW_LEFT] || x < WIDTH / 2)
		cub->map->player_angle -= cub->settings->sensibility;
}

void	ft_handle_speed(t_cub *cub)
{
	if (cub->input[SHIFT] && (cub->input[FORWARD] || cub->input[BACKWARD] \
	|| cub->input[LEFT] || cub->input[RIGHT]))
	{
		cub->speed = 3.0;
		cub->stamina -= 0.8;
		if (cub->stamina <= 0)
		{
			cub->speed = 1.0;
			cub->stamina = 0;
		}
	}
	else if (cub->stamina > 100)
		cub->stamina = 100;
	else
	{
		cub->speed = 1.0;
		cub->stamina += 0.7;
	}
}
