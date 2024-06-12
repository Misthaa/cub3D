/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 02:01:39 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/09 13:53:37 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	_ft_save_settings(int value, char *settings, int fd)
{
	ft_putstr_fd(settings, fd);
	ft_putnbr_fd(value, fd);
	ft_putchar_fd('\n', fd);
}

void	ft_save_settings(t_cub *cub)
{
	int	fd;

	fd = open(".settings", O_WRONLY | O_TRUNC);
	if (cub->settings->n_width)
		_ft_save_settings(cub->settings->n_width, "WIDTH=", fd);
	else
		_ft_save_settings(cub->settings->width, "WIDTH=", fd);
	if (cub->settings->n_height)
		_ft_save_settings(cub->settings->n_height, "HEIGHT=", fd);
	else
		_ft_save_settings(cub->settings->height, "HEIGHT=", fd);
	if (cub->settings->n_sensibility)
		_ft_save_settings(cub->settings->n_sensibility, "SENSITIVITY=0.", fd);
	else
		_ft_save_settings(1, "SENSITIVITY=0.", fd);
	close(fd);
}
