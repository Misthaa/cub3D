/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:54:42 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/10 16:53:54 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*apply_button(void *args, int action)
{
	t_cub	*cub;

	cub = (t_cub *)args;
	if (action == 0 || action == 2)
		return ("APPLY");
	if (action == 1)
	{
		system("killall paplay");
		system("paplay assets/sound/button.ogg &");
		ft_save_settings(cub);
		mlx_loop_end(cub->mlx);
	}
	return (NULL);
}

char	*cancel_button(void *args, int action)
{
	t_cub	*cub;

	cub = (t_cub *)args;
	if (action == 0 || action == 2)
		return ("RETURN");
	if (action == 1)
	{
		system("paplay assets/sound/button.ogg &");
		cub->display = MAIN_MENU;
		cub->settings->n_width = 0;
		cub->settings->n_height = 0;
		cub->settings->n_sensibility = 0;
		cub->settings->n_fov = 0;
		cub->display = MAIN_MENU;
	}
	return (NULL);
}
