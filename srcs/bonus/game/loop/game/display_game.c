/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 00:41:37 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/10 16:53:31 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <sys/time.h>
#include <time.h>

// ---- SHOW GAME ----
// ft_loop_game : This function displays everything the player
//				  sees on the screen.

void	show_game(t_cub *cub)
{
	char	*bullet;

	mlx_clear_window(cub->mlx, cub->win);
	if (cub->settings->d_fps)
		fps_counter(cub);
	if (cub->settings->d_date)
		put_date(cub);
	ft_show_minimap(cub);
	ft_put_rays(cub);
	ft_show_base(cub);
	ft_draw_walls(cub, cub->map->distances);
	mlx_set_font(cub->mlx, cub->win, "assets/font/Pixellari.ttf");
	mlx_set_font_scale(cub->mlx, cub->win, "assets/font/Pixellari.ttf", 69.5f);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img[BASE], 0, 0);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img[MINIMAP], 0, 0);
	print_stamina(cub);
	print_heart(cub);
	print_weapon(cub);
	mlx_set_font_scale(cub->mlx, cub->win, "assets/font/Pixellari.ttf", 69.5f);
	bullet = ft_itoa(cub->sprite->bullets / 6);
	mlx_string_put(cub->mlx, cub->win, cub->settings->width * 0.9f, \
	cub->settings->height * 0.9f, 0xFFFFFFFF, bullet);
	free(bullet);
}

void	display_game(t_cub *cub)
{
	int	x;
	int	y;

	mlx_clear_window(cub->mlx, cub->win);
	center_mouse(cub, &x, &y);
	ft_move_key(cub);
	ft_rotate_key(cub, x);
	ft_handle_speed(cub);
	show_game(cub);
}
