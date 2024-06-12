/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 00:39:26 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/10 01:06:57 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// ---- MOUSE UP DETECTION ----
//	mouse_up : This function detects when the mouse is not pressed.
//			   cub->mouse_left will be = 0.

int	mouse_up(int button, void *args)
{
	t_cub	*cub;

	cub = (t_cub *)args;
	if (button == 1)
		cub->mouse_left = 0;
	return (0);
}

// ---- MOUSE DOWN DETECTION ----
//	mouse_down : This function detects when the mouse is pressed.
//				 cub->mouse_left will be = 1 during pressure.

int	mouse_down(int button, void *args)
{
	t_cub	*cub;

	cub = (t_cub *)args;
	if (button == 1)
		cub->mouse_left = 1;
	return (0);
}

// ---- KEY UP DETECTION ----
//	key_up : This function detects when a key is not pressed. 
//			   cub->input[key] will be = 0.

int	key_up(int key, void *args)
{
	t_cub	*cub;

	cub = (t_cub *)args;
	cub->input[key] = 0;
	return (0);
}

// ---- KEY DOWN DETECTION ----
//	key_down : This function detects when a key is pressed. 
//			   cub->input[key] will be = 1 during pressure.

int	key_down(int key, void *args)
{
	t_cub	*cub;

	cub = (t_cub *)args;
	cub->input[key] = 1;
	if (key == 41 && cub->display != GAME)
	{
		system("pkill paplay");
		mlx_loop_end(cub->mlx);
	}
	else if (key == 41)
	{
		system("paplay assets/sound/cyberpunk_sond.ogg &");
		cub->display = MAIN_MENU;
	}
	return (0);
}
