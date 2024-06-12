/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:03:54 by ehalliez          #+#    #+#             */
/*   Updated: 2024/03/02 00:36:14 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_read_nl(int fd, char *str);
char	*ft_save_line(char *stash);
char	*ft_delete_line(char *str);
char	*free_and_null(char *s1, char *s2, char *s3);
char	*ft_free_return(char *tmp, char *stash);
int		check_newline(char *str);
int		ft_strlen_to_nl(char *str);

#endif