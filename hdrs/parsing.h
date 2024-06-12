/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:23:01 by madegryc          #+#    #+#             */
/*   Updated: 2024/06/10 14:41:14 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "enum.h"

int		ft_parsing(t_cub *cub, char *file);
int		ft_parsing_texture(t_cub *cub, char *line);
int		ft_parsing_color(t_cub *cub, char *line, int boolean);
char	*ft_parsing_map(t_cub *cub, char *line);
int		check_is_alpha(char *str);
int		check_last_color(char *str);
int		count_commas(char *line);
int		is_closed_map(char **str);
int		check_after_fill(t_cub *cub, int fd, char *line);
int		count_line_map(t_cub *cub, int fd, char *line);
int		put_map_struct(t_cub *cub, int fd, char *line);
int		can_access_texture(t_cub *cub);
int		free_tab_error(char **line, char *error, t_cub *cub);
int		free_map(t_cub *cub, char *error);

#endif