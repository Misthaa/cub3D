/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 00:41:37 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/10 02:47:07 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// ---- SHOW GAME ----
// ft_loop_game : This function displays everything the player
//				  sees on the screen.

void	ft_rotate(t_cub *cub)
{
	if (cub->input[ARROW_RIGHT])
		cub->map->player_angle += 0.05;
	if (cub->input[ARROW_LEFT])
		cub->map->player_angle -= 0.05;
	if (cub->input[ARROW_RIGHT])
		cub->map->player_angle += 0.1;
	if (cub->input[ARROW_LEFT])
		cub->map->player_angle -= 0.1;
}

void	show_game(t_cub *cub)
{
	ft_put_rays(cub);
	ft_show_base(cub);
	ft_draw_walls(cub, cub->map->distances);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img[BASE], 0, 0);
}

void	display_game(t_cub *cub)
{
	mlx_clear_window(cub->mlx, cub->win);
	ft_move_key(cub);
	ft_rotate(cub);
	ft_handle_speed(cub);
	show_game(cub);
}
