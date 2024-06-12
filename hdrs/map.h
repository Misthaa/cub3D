/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 01:46:53 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/10 02:16:12 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "enum.h"

void	ft_show_minimap(t_cub *cub);
void	ft_put_player(t_cub *cub);
void	ft_put_pixel(t_cub *cub, int color, int x, int y);
void	ft_put_rays(t_cub *cub);
void	ft_move_player(t_cub *cub, int key);
int		is_wall(t_cub *cub, int x, int y);
void	ft_draw_walls(t_cub *cub, double *distances);
void	ft_show_base(t_cub *cub);
int		mouse_down(int button, void *args);
int		mouse_up(int button, void *args);

#endif