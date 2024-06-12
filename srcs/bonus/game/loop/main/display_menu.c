/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:44:07 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/09 13:53:37 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	display_menu(t_cub *cub)
{
	mlx_clear_window(cub->mlx, cub->win);
	ft_create_menu(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img[MENU], 0, 0);
}
