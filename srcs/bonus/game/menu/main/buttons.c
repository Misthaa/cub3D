/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:48:15 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/10 03:21:15 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*play_button(void *args, int action)
{
	t_cub	*cub;

	cub = (t_cub *)args;
	if (action == 0 || action == 2)
		return ("PLAY");
	if (action == 1)
	{
		system("killall paplay");
		system("paplay assets/sound/button.ogg &");
		cub->display = GAME;
		return (NULL);
	}
	return (NULL);
}

char	*settings_button(void *args, int action)
{
	t_cub	*cub;

	cub = (t_cub *)args;
	if (action == 0 || action == 2)
		return ("SETTINGS");
	if (action == 1)
	{
		system("paplay assets/sound/button.ogg &");
		cub->display = SETTINGS;
		return (NULL);
	}
	return (NULL);
}

char	*quit_button(void *args, int action)
{
	t_cub	*cub;

	cub = (t_cub *)args;
	if (action == 0 || action == 2)
		return ("QUIT");
	if (action == 1)
	{
		mlx_loop_end(cub->mlx);
		system("killall paplay");
		system("paplay assets/sound/button.ogg &");
	}
	return (NULL);
}
