/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 02:00:19 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/09 13:53:37 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

// 				   --- COLORIZE CELL ---
// ft_colorize_case : This function will colorize 
//					  the cell the player is in (for debug)

void	ft_colorize_case(t_cub *cub)
{
	int	tile_x;
	int	tile_y;
	int	x;
	int	y;

	tile_x = cub->map->player_pos[X] / TILE_SIZE;
	tile_y = cub->map->player_pos[Y] / TILE_SIZE;
	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			ft_put_pixel(cub, PLAYER_CASE_COLOR, tile_x * \
						TILE_SIZE + x, \
				tile_y * TILE_SIZE + y);
			x++;
		}
		y++;
	}
}

// 				   --- PUT PLAYER ---
// ft_put_player : This function will draw the player 
//				   on the map

void	ft_put_player(t_cub *cub)
{
	int	x;
	int	y;
	int	player_x;
	int	player_y;

	ft_colorize_case(cub);
	player_x = (int)cub->map->player_pos[X] - PLAYER_SIZE / 2;
	player_y = (int)cub->map->player_pos[Y] - PLAYER_SIZE / 2;
	y = 0;
	while (y < PLAYER_SIZE)
	{
		x = 0;
		while (x < PLAYER_SIZE)
		{
			ft_put_pixel(cub, PLAYER_COLOR, \
				player_x + x, \
				player_y + y);
			x++;
		}
		y++;
	}
}
