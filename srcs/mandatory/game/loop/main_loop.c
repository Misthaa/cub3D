/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 00:41:37 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/10 02:35:58 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// ---- LOOP GAME ----
// ft_main_loop : This function is the main process of the game
//				  she is in a mlx loop and every X miliseconds
//				  all of this (input, map, game) will be updated and checked

int	ft_main_loop(void *args)
{
	t_cub			*cub;

	cub = (t_cub *)args;
	display_game(cub);
	return (0);
}
