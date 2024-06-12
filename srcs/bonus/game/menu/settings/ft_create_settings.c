/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_settings.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:11:53 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/10 01:07:00 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <fcntl.h>

int	is_float(const char *str)
{
	int	has_decimal_point;

	has_decimal_point = 0;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (*str == '.')
		{
			if (has_decimal_point)
				return (0);
			has_decimal_point = 1;
		}
		else if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	if (has_decimal_point && *str - 1 == '.')
		return (0);
	return (1);
}

int	is_number(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str) && *str != '\n' && \
			(*str != '.' && *str + 1 != '.'))
			return (0);
		str++;
	}
	return (1);
}

int	ft_assign_settings(t_settings *settings, char *line, int i)
{
	if (!ft_strncmp(line, "WIDTH=", 6) && is_number(line + 6))
		settings->width = ft_atoi(line + 6);
	else if (!ft_strncmp(line, "HEIGHT=", 7) && is_number(line + 7))
		settings->height = ft_atoi(line + 7);
	else if (!ft_strncmp(line, "SENSITIVITY=", 12))
		settings->sensibility = atof(line + 12);
	else
	{
		ft_putstr_fd("Invalid settings found in .settings at line ", 2);
		ft_putnbr_fd(i, 2);
		ft_putstr_fd(" : ", 2);
		ft_putstr_fd(line, 2);
		ft_putchar_fd('\n', 2);
		return (0);
	}
	return (1);
}

int	ft_create_settings(t_settings *settings)
{
	settings->width = 1280;
	settings->height = 900;
	settings->sensibility = 0.1;
	return (0);
}

int	ft_read_settings(t_settings *settings)
{
	int		i;
	char	*line;
	int		fd;

	i = 0;
	fd = open(".settings", O_RDWR);
	if (fd < 1)
		return (ft_create_settings(settings));
	line = get_next_line(fd);
	if (!line)
		return (ft_create_settings(settings));
	while (line)
	{
		i++;
		if (!ft_assign_settings(settings, line, i))
			return (ft_create_settings(settings));
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
