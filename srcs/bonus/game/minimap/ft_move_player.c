/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 07:03:16 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/10 01:07:04 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <math.h>

void	_ft_move_player(t_cub *cub, double move_x, double move_y);

// 					---- MOVE PLAYER ----
// ft_move_player : This function will move the player in the right
//					direction according to the key.
//					An angle calc will be made for move the player
//					in the correct angle.
// For increase the speed we can increase cub->speed

void	ft_move_player(t_cub *cub, int key)
{
	double	move_x;
	double	move_y;

	if (key == FORWARD)
	{
		move_x = cos(cub->map->player_angle) * cub->speed;
		move_y = sin(cub->map->player_angle) * cub->speed;
	}
	else if (key == BACKWARD)
	{
		move_x = -cos(cub->map->player_angle) * cub->speed;
		move_y = -sin(cub->map->player_angle) * cub->speed;
	}
	else if (key == LEFT)
	{
		move_x = cos(cub->map->player_angle - (PI / 2)) * cub->speed;
		move_y = sin(cub->map->player_angle - (PI / 2)) * cub->speed;
	}
	else
	{
		move_x = cos(cub->map->player_angle + (PI / 2)) * cub->speed;
		move_y = sin(cub->map->player_angle + (PI / 2)) * cub->speed;
	}
	_ft_move_player(cub, move_x, move_y);
}

void	_ft_move_player(t_cub *cub, double move_x, double move_y)
{
	move_x = cub->map->player_pos[X] + move_x;
	move_y = cub->map->player_pos[Y] + move_y;
	if (!is_wall(cub, (int)move_x, (int)move_y) && \
		!is_wall(cub, (int)move_x - 1, (int)move_y - 1) && \
		!is_wall(cub, (int)move_x + 1, (int)move_y + 1))
	{
		cub->map->player_pos[X] = move_x;
		cub->map->player_pos[Y] = move_y;
	}
}
