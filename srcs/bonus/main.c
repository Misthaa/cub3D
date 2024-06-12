/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 23:38:51 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/10 03:22:13 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	init_values(t_cub *cub);

int	main(int ac, char **av)
{
	t_cub		cub;
	t_settings	settings;

	ft_read_settings(&settings);
	cub.settings = &settings;
	if (init_cub(&cub, ac, av) == 0)
		return (1);
	if (!init_values(&cub))
	{
		clean_cub(&cub);
		exit(1);
	}
	mlx_on_event(cub.mlx, cub.win, MLX_KEYDOWN, key_down, &cub);
	mlx_on_event(cub.mlx, cub.win, MLX_KEYUP, key_up, &cub);
	mlx_on_event(cub.mlx, cub.win, MLX_MOUSEDOWN, mouse_down, &cub);
	mlx_on_event(cub.mlx, cub.win, MLX_MOUSEUP, mouse_up, &cub);
	mlx_on_event(cub.mlx, cub.win, MLX_WINDOW_EVENT, window_hook, &cub);
	mlx_set_fps_goal(cub.mlx, 60);
	mlx_loop_hook(cub.mlx, ft_main_loop, &cub);
	mlx_loop(cub.mlx);
	clean_cub(&cub);
	return (0);
}

int	init_values(t_cub *cub)
{
	cub->display = MAIN_MENU;
	cub->settings->n_width = 0;
	cub->settings->n_height = 0;
	cub->settings->n_sensibility = 0;
	cub->settings->n_fov = 0;
	cub->map->distances = malloc(sizeof(double) * (cub->settings->width + 1));
	if (!cub->map->distances)
		return (0);
	cub->map->x_ray = malloc(sizeof(double) * (cub->settings->width + 1));
	if (!cub->map->x_ray)
		return (0);
	cub->map->y_ray = malloc(sizeof(double) * (cub->settings->width + 1));
	if (!cub->map->y_ray)
		return (0);
	cub->map->ray_side = malloc(sizeof(int) * (cub->settings->width + 1));
	if (!cub->map->ray_side)
		return (0);
	cub->map->ray_orientation = malloc(sizeof(int) * \
	(cub->settings->width + 1));
	if (!cub->map->ray_orientation)
		return (0);
	return (1);
}
