/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 00:40:30 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/10 02:25:37 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

int		key_up(int key, void *args);
int		key_down(int key, void *args);
int		mouse_up(int button, void *args);
int		mouse_down(int button, void *args);
void	init_input(t_cub *cub);
int		ft_main_loop(void *args);
void	display_menu(t_cub *cub);
void	display_game(t_cub *cub);
void	display_settings(t_cub *cub);
void	center_mouse(t_cub *cub, int *x, int *y);
void	ft_move_key(t_cub *cub);
void	ft_rotate_key(t_cub *cub, int x);
void	ft_handle_speed(t_cub *cub);
void	print_weapon(t_cub *cub);
void	print_stamina(t_cub *cub);
void	print_heart(t_cub *cub);
void	fps_counter(t_cub *cub);
void	put_date(t_cub *cub);

#endif