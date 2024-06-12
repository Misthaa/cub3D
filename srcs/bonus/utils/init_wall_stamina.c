/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wall_stamina.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:49:12 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/09 13:53:37 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	_init_stamina(t_cub *cub)
{
	int	img_width;
	int	img_height;

	cub->sprite->stamina[7] = mlx_png_file_to_image(cub->mlx,
			"assets/sprites/stamina/stamina7.png", &img_width, &img_height);
	cub->sprite->stamina[8] = mlx_png_file_to_image(cub->mlx,
			"assets/sprites/stamina/stamina8.png", &img_width, &img_height);
	cub->sprite->stamina[9] = mlx_png_file_to_image(cub->mlx,
			"assets/sprites/stamina/stamina9.png", &img_width, &img_height);
	cub->sprite->stamina[10] = mlx_png_file_to_image(cub->mlx,
			"assets/sprites/stamina/stamina10.png", &img_width, &img_height);
	cub->sprite->stamina[11] = mlx_png_file_to_image(cub->mlx,
			"assets/sprites/stamina/stamina11.png", &img_width, &img_height);
	cub->sprite->stamina[12] = mlx_png_file_to_image(cub->mlx,
			"assets/sprites/stamina/stamina12.png", &img_width, &img_height);
	cub->sprite->stamina[13] = NULL;
}

void	init_stamina(t_cub *cub)
{
	int	img_width;
	int	img_height;

	cub->sprite->stamina[0] = mlx_png_file_to_image(cub->mlx,
			"assets/sprites/stamina/stamina0.png", &img_width, &img_height);
	cub->sprite->stamina[1] = mlx_png_file_to_image(cub->mlx,
			"assets/sprites/stamina/stamina1.png", &img_width, &img_height);
	cub->sprite->stamina[2] = mlx_png_file_to_image(cub->mlx,
			"assets/sprites/stamina/stamina2.png", &img_width, &img_height);
	cub->sprite->stamina[3] = mlx_png_file_to_image(cub->mlx,
			"assets/sprites/stamina/stamina3.png", &img_width, &img_height);
	cub->sprite->stamina[4] = mlx_png_file_to_image(cub->mlx,
			"assets/sprites/stamina/stamina4.png", &img_width, &img_height);
	cub->sprite->stamina[5] = mlx_png_file_to_image(cub->mlx,
			"assets/sprites/stamina/stamina5.png", &img_width, &img_height);
	cub->sprite->stamina[6] = mlx_png_file_to_image(cub->mlx,
			"assets/sprites/stamina/stamina6.png", &img_width, &img_height);
	_init_stamina(cub);
}

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
	cub->sprite->wall[4]->texture = mlx_png_file_to_image(cub->mlx,
			"assets/sprites/wall/wall-door.png", &img_width, &img_height);
	cub->sprite->wall[4]->width = img_width;
	cub->sprite->wall[4]->height = img_height;
}

void	init_wall(t_cub *cub)
{
	int	img_width;
	int	img_height;

	cub->sprite->wall[0] = malloc(sizeof(t_textures));
	cub->sprite->wall[1] = malloc(sizeof(t_textures));
	cub->sprite->wall[2] = malloc(sizeof(t_textures));
	cub->sprite->wall[3] = malloc(sizeof(t_textures));
	cub->sprite->wall[4] = malloc(sizeof(t_textures));
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
