/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_hud.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 02:24:30 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/10 14:41:30 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <sys/time.h>
#include <time.h>

// ---- PRINT WEAPON ----
//	print_weapon : This function displays the weapon of the player
//				   on the screen. The weapon animate when you right click.

void	print_weapon(t_cub *cub)
{
	static double	i = 1;
	static double	time = 0;

	if (i == 1)
		mlx_put_image_to_window(cub->mlx, cub->win, cub->sprite->weapon[0], \
			cub->settings->width * 0.55f, cub->settings->height * 0.21f);
	if ((time > 1 && cub->mouse_left == 1) || i != 1)
	{
		if (cub->sprite->bullets > 0)
		{
			mlx_put_image_to_window(cub->mlx, cub->win, \
			cub->sprite->weapon[(int)i], \
			cub->settings->width * 0.55f, cub->settings->height * 0.21f);
			i += 0.55;
			time = 0;
			if (cub->sprite->bullets > 0)
				cub->sprite->bullets--;
			system("paplay assets/sound/weapon.ogg &");
		}
		else if (cub->sprite->bullets == 0)
			system("paplay assets/sound/empty_gun.ogg &");
		if (i > 4)
			i = 1;
	}
	time += 0.12;
}

// ---- PRINT STAMINA ----
//	print_stamina : This function displays the stamina of the player
//					 on the screen. The stamina will decrease when the player
//					 runs and increase when he stops.

void	print_stamina(t_cub *cub)
{
	mlx_put_image_to_window(cub->mlx, cub->win, \
	cub->sprite->stamina[((int)(cub->stamina * 12) / 100)], \
		cub->settings->width * 0.35f, cub->settings->height * 0.80f);
}

// ---- PRINT HEART ----
//	print_heart : This function displays the heart of the player
//				  on the screen. The heart will change every X miliseconds
//				  to simulate a beating heart.
//				  The speed of the heart will change when the player runs.

void	print_heart(t_cub *cub)
{
	static double	i = 0;

	mlx_put_image_to_window(cub->mlx, cub->win, cub->sprite->heart[(int)i], \
	cub->settings->width * 0.35f, cub->settings->height * 0.80f);
	if (cub->speed == 1.0)
		i += 0.3;
	else
		i += 0.55;
	if (i > 6)
		i = 0;
}

void	fps_counter(t_cub *cub)
{
	static clock_t	last_time = 0;
	static int		frame_count = 0;
	static float	fps_sum = 0.0;
	clock_t			current_time;
	float			fps;

	current_time = clock();
	fps = CLOCKS_PER_SEC / (float)(current_time - last_time);
	last_time = current_time;
	fps_sum += fps;
	frame_count++;
	ft_itoa(fps);
	mlx_set_font_scale(cub->mlx, cub->win, "assets/font/Pixellari.ttf", 30.0f);
	mlx_string_put(cub->mlx, cub->win, cub->settings->width * 0.97f, \
	cub->settings->height * 0.03f, 0xFFFFFFFF, ft_itoa(fps));
}

void	put_date(t_cub *cub)
{
	char		s_now[256];
	char		s_day[256];
	time_t		now;
	struct tm	tm_now;

	now = time (NULL);
	tm_now = *localtime (&now);
	strftime (s_now, sizeof s_now, "%d/%m/%Y", &tm_now);
	strftime (s_day, sizeof s_day, "%H:%M:%S", &tm_now);
	mlx_set_font_scale(cub->mlx, cub->win, "assets/font/Pixellari.ttf", 30.0f);
	mlx_string_put(cub->mlx, cub->win, cub->settings->width * \
	0.874f, cub->settings->height * 0.10f, 0xFFFFFFFF, s_now);
	mlx_string_put(cub->mlx, cub->win, cub->settings->width * \
	0.90f, cub->settings->height * 0.15f, 0xFFFFFFFF, s_day);
}
