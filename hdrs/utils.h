/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 00:56:23 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/10 14:41:20 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "enum.h"

void	clean_cub(t_cub *cub);
int		get_current_time(void);
int		init_cub(t_cub *cub, int ac, char **av);
void	assign_map(t_cub *cub);
char	*ft_strjoin_free_both(char *s1, char *s2);
int		ft_error(char *str, t_cub *cub);
void	init_heart(t_cub *cub);
void	init_stamina(t_cub *cub);
void	init_weapon(t_cub *cub);
void	init_slider(t_cub *cub);
void	init_wall(t_cub *cub);
void	init_button(t_cub *cub);
void	_get_player_angle(t_cub *cub);
void	get_player_angle(t_cub *cub);
int		get_map_height(t_cub *cub);
int		get_wall_height(t_cub *cub, double *distances, int x);
int		window_hook(int event, void *param);

#endif