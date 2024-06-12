/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 00:52:50 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/10 14:42:28 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//	---- FREE_IMG FUNCTION ----
//	Free all the images in the sprite struct

int	window_hook(int event, void *param)
{
	t_cub	*cub;

	cub = param;
	if (event == 0)
	{
		if (cub->display == MAIN_MENU || cub->display == SETTINGS)
			system("killall paplay");
		clean_cub(cub);
		exit(0);
	}
	return (0);
}

void	free_img(t_cub *cub)
{
	int	i;

	i = -1;
	while (++i < 6)
		mlx_destroy_image(cub->mlx, cub->sprite->heart[i]);
	i = -1;
	while (++i < 13)
		mlx_destroy_image(cub->mlx, cub->sprite->stamina[i]);
	i = -1;
	while (++i < 5)
		mlx_destroy_image(cub->mlx, cub->sprite->weapon[i]);
	i = -1;
	while (++i < 4)
		mlx_destroy_image(cub->mlx, cub->sprite->slider[i]);
	i = -1;
	while (++i < 6)
		mlx_destroy_image(cub->mlx, cub->sprite->button[i]);
}

//	---- CLEAN FUNCTION ----
//	Clean all the component in the cub struct and destroy MLX component

void	clean_image(t_cub *cub)
{
	mlx_destroy_image(cub->mlx, cub->img[MENU]);
	mlx_destroy_image(cub->mlx, cub->img[BASE]);
	mlx_destroy_image(cub->mlx, cub->img[MINIMAP]);
	mlx_destroy_image(cub->mlx, cub->img[M_BACK]);
	mlx_destroy_image(cub->mlx, cub->img[M_BACK_2]);
	mlx_destroy_image(cub->mlx, cub->img[S_BACK]);
	mlx_destroy_image(cub->mlx, cub->img[CHECKED]);
	mlx_destroy_image(cub->mlx, cub->img[UNCHECKED]);
	mlx_destroy_image(cub->mlx, cub->sprite->wall[0]->texture);
	mlx_destroy_image(cub->mlx, cub->sprite->wall[1]->texture);
	mlx_destroy_image(cub->mlx, cub->sprite->wall[2]->texture);
	mlx_destroy_image(cub->mlx, cub->sprite->wall[3]->texture);
	mlx_destroy_image(cub->mlx, cub->sprite->wall[4]->texture);
	free(cub->sprite->wall[0]);
	free(cub->sprite->wall[1]);
	free(cub->sprite->wall[2]);
	free(cub->sprite->wall[3]);
	free(cub->sprite->wall[4]);
	free_img(cub);
}

void	clean_parse(t_cub *cub)
{
	free(cub->parse->no);
	free(cub->parse->so);
	free(cub->parse->we);
	free(cub->parse->ea);
	free(cub->parse);
}

void	clean_cub(t_cub *cub)
{
	if (cub->map->distances)
		free(cub->map->distances);
	if (cub->map->x_ray)
		free(cub->map->x_ray);
	if (cub->map->y_ray)
		free(cub->map->y_ray);
	if (cub->map->ray_side)
		free(cub->map->ray_side);
	if (cub->map->ray_orientation)
		free(cub->map->ray_orientation);
	clean_image(cub);
	mlx_destroy_window(cub->mlx, cub->win);
	mlx_destroy_display(cub->mlx);
	ft_free_ctab(cub->map->map);
	free(cub->map);
	free(cub->sprite);
	clean_parse(cub);
}
