# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 13:50:42 by ehalliez          #+#    #+#              #
#    Updated: 2024/06/05 19:37:14 by madegryc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MY-SOURCES = ft_get_last_letter.c ft_count_letters.c ft_find_letter.c ft_free_ttab.c ft_free_ctab.c ft_count_strtab.c ft_print_ctab.c get_next_line_bonus.c get_next_line_utils_bonus.c ft_printf.c ft_print_adress.c ft_check_param.c ft_putnbr_base.c ft_split.c ft_atoi.c ft_striteri.c ft_strmapi.c ft_substr.c ft_strtrim.c ft_itoa.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_strjoin.c ft_memchr.c ft_memcmp.c ft_isalpha.c ft_strncmp.c ft_strnstr.c ft_strchr.c ft_strrchr.c ft_strdup.c ft_strlcpy.c ft_strlcat.c ft_strlen.c ft_isprint.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_calloc.c ft_toupper.c ft_tolower.c ft_tablen.c
				
MY-OBJECTS = $(MY-SOURCES:.c=.o)

MY-BONUS = ft_lstmap.c ft_lstiter.c ft_lstclear.c ft_lstdelone.c ft_lstadd_back.c ft_lstlast.c ft_lstsize.c ft_lstadd_front.c ft_lstnew.c

MY-BONUSOBJ = $(MY-BONUS:.c=.o)

NAME = libft.a

CFLAGS = -Werror -Wall -Wextra -g

CC = clang

all: $(NAME)

$(NAME): $(MY-OBJECTS)
	ar rcs $(NAME) $(MY-OBJECTS) 

clean:
	rm -f $(MY-OBJECTS) $(MY-BONUSOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

bonus: $(MY-OBJECTS) $(MY-BONUSOBJ)
	ar rcs $(NAME) $(MY-OBJECTS) $(MY-BONUSOBJ)
	
.PHONY: all clean fclean re bonus
