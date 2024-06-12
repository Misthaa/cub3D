/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:49:12 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/10 02:51:45 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	_init_wall(t_cub *cub)
{
	int	img_width;
	int	img_height;

	cub->sprite->wall[2]->texture = mlx_png_file_to_image(cub->mlx, \
		cub->parse->ea, &img_width, &img_height);
	cub->sprite->wall[2]->width = img_width;
	cub->sprite->wall[2]->height = img_height;
	cub->sprite->wall[3]->texture = mlx_png_file_to_image(cub->mlx,
			cub->parse->we, &img_width, &img_height);
	cub->sprite->wall[3]->width = img_width;
	cub->sprite->wall[3]->height = img_height;
}

void	init_wall(t_cub *cub)
{
	int	img_width;
	int	img_height;

	cub->sprite->wall[0] = malloc(sizeof(t_textures));
	cub->sprite->wall[1] = malloc(sizeof(t_textures));
	cub->sprite->wall[2] = malloc(sizeof(t_textures));
	cub->sprite->wall[3] = malloc(sizeof(t_textures));
	cub->sprite->wall[0]->texture = mlx_png_file_to_image(cub->mlx,
			cub->parse->no, &img_width, &img_height);
	cub->sprite->wall[0]->width = img_width;
	cub->sprite->wall[0]->height = img_height;
	cub->sprite->wall[1]->texture = mlx_png_file_to_image(cub->mlx,
			cub->parse->so, &img_width, &img_height);
	cub->sprite->wall[1]->width = img_width;
	cub->sprite->wall[1]->height = img_height;
	_init_wall(cub);
}
