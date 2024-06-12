/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 00:52:50 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/10 03:01:59 by ehalliez         ###   ########.fr       */
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
		clean_cub(cub);
		exit(0);
	}
	return (0);
}

//	---- CLEAN FUNCTION ----
//	Clean all the component in the cub struct and destroy MLX component

void	clean_image(t_cub *cub)
{
	mlx_destroy_image(cub->mlx, cub->img[BASE]);
	mlx_destroy_image(cub->mlx, cub->sprite->wall[0]->texture);
	mlx_destroy_image(cub->mlx, cub->sprite->wall[1]->texture);
	mlx_destroy_image(cub->mlx, cub->sprite->wall[2]->texture);
	mlx_destroy_image(cub->mlx, cub->sprite->wall[3]->texture);
	free(cub->sprite->wall[0]);
	free(cub->sprite->wall[1]);
	free(cub->sprite->wall[2]);
	free(cub->sprite->wall[3]);
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
