/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 00:41:37 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/09 13:54:53 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// ---- LOOP GAME ----
// ft_main_loop : This function is the main process of the game
//				  she is in a mlx loop and every X miliseconds
//				  all of this (input, map, game) will be updated and checked

int	ft_main_loop(void *args)
{
	static double	i = 0;
	t_cub			*cub;

	cub = (t_cub *)args;
	if (cub->display == GAME)
		mlx_mouse_hide();
	else
		mlx_mouse_show();
	if (cub->display == MAIN_MENU)
		display_menu(cub);
	else if (cub->display == GAME)
		display_game(cub);
	else if (cub->display == SETTINGS)
		display_settings(cub);
	if (cub->input[8] == 1 && !cub->pressed)
	{
		cub->pressed = 1;
		cub->input[8] = 0;
		i = 0;
	}
	if (i < 4)
		i += 0.20;
	if (i >= 4)
		cub->pressed = 0;
	return (0);
}
