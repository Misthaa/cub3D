/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 00:54:08 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/10 03:00:08 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// ---- INITIALIZATION ----
// init_cub : Init all the prerequisites in the cub 
// 			  struct for starting the game.
// All return are verify for security, some may be useless.

void	init_cub_component(t_cub *cub)
{
	cub->win = mlx_new_window(cub->mlx, WIDTH, \
	HEIGHT, "cub3D");
	cub->img[BASE] = mlx_new_image(cub->mlx, \
	WIDTH, HEIGHT);
	cub->map->distances = NULL;
	cub->map->x_ray = NULL;
	cub->map->y_ray = NULL;
	cub->map->ray_side = NULL;
	cub->map->ray_orientation = NULL;
}

int	init_cub(t_cub *cub, int ac, char **av)
{
	if (ac != 2)
		return (ft_error("Invalid number of arguments\n", cub));
	assign_map(cub);
	if (ft_parsing(cub, av[1]) == 0)
	{
		free(cub->map);
		free(cub->parse->no);
		free(cub->parse->so);
		free(cub->parse->we);
		free(cub->parse->ea);
		free(cub->parse);
		free(cub->sprite);
		return (0);
	}
	cub->mlx = mlx_init();
	init_cub_component(cub);
	init_wall(cub);
	init_input(cub);
	get_player_angle(cub);
	cub->map->map_height = get_map_height(cub);
	return (1);
}

void	assign_map(t_cub *cub)
{
	cub->map = malloc(sizeof(t_game_map));
	cub->parse = malloc(sizeof(t_parse));
	cub->sprite = malloc(sizeof(t_sprite));
	if (!cub->map)
		return ;
	cub->map->position[X] = 25;
	cub->map->position[Y] = 25;
	cub->stamina = 100;
	cub->parse->check_floor = 0;
	cub->parse->check_sky = 0;
	cub->parse->check = 0;
	cub->parse->count_line_map = 0;
	cub->sprite->bullets = 180;
	cub->parse->has_player = 0;
	cub->parse->no = NULL;
	cub->parse->so = NULL;
	cub->parse->we = NULL;
	cub->parse->ea = NULL;
	cub->parse->floor_color = -1;
	cub->parse->sky_color = -1;
	cub->map->distances = NULL;
	cub->map->x_ray = NULL;
	cub->map->y_ray = NULL;
	cub->map->ray_side = NULL;
	cub->map->ray_orientation = NULL;
}

// ---- Init input tab --- 
// init_input : To avoid invalid read, init all to 0

void	init_input(t_cub *cub)
{
	int	i;

	i = 0;
	cub->mouse_left = 0;
	cub->pressed = 0;
	while (i < 500)
	{
		cub->input[i] = 0;
		i++;
	}
}
