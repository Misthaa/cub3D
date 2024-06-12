/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 23:06:53 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/10 02:16:40 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENU_H
# define MENU_H

void	ft_create_menu(t_cub *cub);
void	ft_create_background(t_cub *cub, int color);
void	ft_create_button(t_cub *cub, int pos[2], \
char *(*f)(void *, int), int choice);
void	ft_create_button_text(t_cub *cub, int pos[2], char *(*f)(void *, int));
char	*play_button(void *args, int action);
char	*settings_button(void *args, int action);
char	*quit_button(void *args, int action);
char	*apply_button(void *args, int action);
char	*cancel_button(void *args, int action);
int		ft_read_settings(t_settings *settings);
void	ft_save_settings(t_cub *cub);
void	display_check_box(t_cub *cub);

#endif