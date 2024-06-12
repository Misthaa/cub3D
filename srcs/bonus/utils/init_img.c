/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:15:24 by madegryc          #+#    #+#             */
/*   Updated: 2024/06/09 13:53:37 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_button(t_cub *cub)
{
	int	img_width;
	int	img_height;

	cub->sprite->button[0] = mlx_png_file_to_image(cub->mlx, \
		"assets/sprites/button/play1.png", &img_width, &img_height);
	cub->sprite->button[1] = mlx_png_file_to_image(cub->mlx, \
		"assets/sprites/button/play2.png", &img_width, &img_height);
	cub->sprite->button[2] = mlx_png_file_to_image(cub->mlx, \
		"assets/sprites/button/settings1.png", &img_width, &img_height);
	cub->sprite->button[3] = mlx_png_file_to_image(cub->mlx, \
		"assets/sprites/button/settings2.png", &img_width, &img_height);
	cub->sprite->button[4] = mlx_png_file_to_image(cub->mlx, \
		"assets/sprites/button/quit1.png", &img_width, &img_height);
	cub->sprite->button[5] = mlx_png_file_to_image(cub->mlx, \
		"assets/sprites/button/quit2.png", &img_width, &img_height);
}

void	init_slider(t_cub *cub)
{
	int	img_width;
	int	img_height;

	cub->sprite->slider[0] = mlx_png_file_to_image(cub->mlx,
			"assets/sprites/settings/slider1.png", &img_width, &img_height);
	cub->sprite->slider[1] = mlx_png_file_to_image(cub->mlx,
			"assets/sprites/settings/slider2.png", &img_width, &img_height);
	cub->sprite->slider[2] = mlx_png_file_to_image(cub->mlx,
			"assets/sprites/settings/slider3.png", &img_width, &img_height);
	cub->sprite->slider[3] = mlx_png_file_to_image(cub->mlx,
			"assets/sprites/settings/slider4.png", &img_width, &img_height);
}

void	init_heart(t_cub *cub)
{
	int	img_width;
	int	img_height;

	cub->sprite->heart[0] = mlx_png_file_to_image(cub->mlx,
			"assets/sprites/heart/heart1.png", &img_width, &img_height);
	cub->sprite->heart[1] = mlx_png_file_to_image(cub->mlx,
			"assets/sprites/heart/heart2.png", &img_width, &img_height);
	cub->sprite->heart[2] = mlx_png_file_to_image(cub->mlx,
			"assets/sprites/heart/heart3.png", &img_width, &img_height);
	cub->sprite->heart[3] = mlx_png_file_to_image(cub->mlx,
			"assets/sprites/heart/heart4.png", &img_width, &img_height);
	cub->sprite->heart[4] = mlx_png_file_to_image(cub->mlx,
			"assets/sprites/heart/heart5.png", &img_width, &img_height);
	cub->sprite->heart[5] = mlx_png_file_to_image(cub->mlx,
			"assets/sprites/heart/heart6.png", &img_width, &img_height);
}

void	init_weapon(t_cub *cub)
{
	int	img_width;
	int	img_height;

	cub->sprite->weapon[0] = mlx_png_file_to_image(cub->mlx,
			"assets/sprites/weapon/weapon1.png", &img_width, &img_height);
	cub->sprite->weapon[1] = mlx_png_file_to_image(cub->mlx,
			"assets/sprites/weapon/weapon2.png", &img_width, &img_height);
	cub->sprite->weapon[2] = mlx_png_file_to_image(cub->mlx,
			"assets/sprites/weapon/weapon3.png", &img_width, &img_height);
	cub->sprite->weapon[3] = mlx_png_file_to_image(cub->mlx,
			"assets/sprites/weapon/weapon4.png", &img_width, &img_height);
	cub->sprite->weapon[4] = mlx_png_file_to_image(cub->mlx,
			"assets/sprites/weapon/weapon5.png", &img_width, &img_height);
}
