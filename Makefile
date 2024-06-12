# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 13:50:42 by ehalliez          #+#    #+#              #
#    Updated: 2024/06/10 15:28:11 by ehalliez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cyan = /bin/echo -e "\x1b[35m $1\x1b[0m"
.SILENT:

SRC_DIR = srcs
BUILD_DIR = $(SRC_DIR)/build

MY-SOURCES = 	srcs/mandatory/main.c \
				srcs/mandatory/game/loop/game/ft_move_player.c \
				srcs/mandatory/game/raycasting/ft_put_rays.c \
				srcs/mandatory/game/raycasting/ft_show_base.c \
				srcs/mandatory/game/raycasting/ft_draw_walls.c \
				srcs/mandatory/game/raycasting/walls_utils.c \
				srcs/mandatory/game/loop/main_loop.c \
				srcs/mandatory/game/loop/utils/keyboard_input.c \
				srcs/mandatory/game/loop/game/display_game.c \
				srcs/mandatory/game/loop/game/utils_game.c \
				srcs/mandatory/utils/clean.c \
				srcs/mandatory/utils/init.c \
				srcs/mandatory/utils/init_wall.c\
				srcs/mandatory/utils/utils.c\
				srcs/mandatory/utils/init_utils.c\
				srcs/mandatory/parsing/parsing.c\
				srcs/mandatory/parsing/parsing_utils.c\
				srcs/mandatory/parsing/parsing_map.c\
				srcs/mandatory/parsing/parsing_colors.c\
				srcs/mandatory/parsing/parsing_texture.c\
				srcs/mandatory/parsing/parsing_check.c\

MY-OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(MY-SOURCES))

MY-B-SOURCES =  srcs/bonus/main.c \
				srcs/bonus/game/minimap/ft_move_player.c \
				srcs/bonus/game/minimap/ft_put_pixel.c \
				srcs/bonus/game/minimap/ft_put_player.c \
				srcs/bonus/game/minimap/ft_put_rays.c \
				srcs/bonus/game/minimap/ft_show_minimap_utils.c \
				srcs/bonus/game/minimap/ft_show_minimap.c \
				srcs/bonus/game/minimap/ft_check_door.c \
				srcs/bonus/game/raycasting/ft_draw_walls.c \
				srcs/bonus/game/raycasting/ft_show_base.c \
				srcs/bonus/game/raycasting/walls_utils.c \
				srcs/bonus/game/loop/main_loop.c \
				srcs/bonus/game/loop/utils/keyboard_input.c \
				srcs/bonus/game/loop/main/display_menu.c \
				srcs/bonus/game/loop/game/display_game.c \
				srcs/bonus/game/loop/game/display_hud.c \
				srcs/bonus/game/loop/game/utils_game.c \
				srcs/bonus/game/loop/settings/display_settings.c \
				srcs/bonus/game/loop/settings/slider_res.c \
				srcs/bonus/game/loop/settings/slider_sensitivity.c \
				srcs/bonus/game/loop/settings/check_box.c \
				srcs/bonus/game/menu/main/buttons.c \
				srcs/bonus/game/menu/main/ft_create_menu.c \
				srcs/bonus/game/menu/utils/ft_create_background.c \
				srcs/bonus/game/menu/utils/ft_create_button.c \
				srcs/bonus/game/menu/settings/buttons.c \
				srcs/bonus/game/menu/settings/ft_create_settings.c \
				srcs/bonus/game/menu/settings/ft_save_settings.c \
				srcs/bonus/utils/clean.c \
				srcs/bonus/utils/init.c \
				srcs/bonus/utils/init_img.c\
				srcs/bonus/utils/init_wall_stamina.c\
				srcs/bonus/utils/utils.c\
				srcs/bonus/utils/init_utils.c\
				srcs/bonus/parsing/parsing.c\
				srcs/bonus/parsing/parsing_utils.c\
				srcs/bonus/parsing/parsing_map.c\
				srcs/bonus/parsing/parsing_colors.c\
				srcs/bonus/parsing/parsing_texture.c\
				srcs/bonus/parsing/parsing_check.c\
			
MY-B-OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(MY-B-SOURCES))

INCLUDES = \
	-MMD -MP -I ./hdrs/ \

NAME = cub3D

MAKE_N = make -s -C

MAKE_B = make bonus -s -C

MAKE_C = make clean -s -C

MAKE_F = make fclean -s -C

RM = rm -rf

LibftPath = libs/libft

MacroPath = libs/MacroLibX

CFLAGS = -Wall -Wextra -g -Werror

CC = clang

all: $(NAME)
	@echo "\033[92mMake finished.\033[0m"

$(NAME): $(MY-OBJECTS)
	$(MAKE_N) $(MacroPath) -j
	$(MAKE_B) $(LibftPath)
	$(CC) -o $(NAME) $(CFLAGS) $(INCLUDES) $(MY-OBJECTS) $(MacroPath)/libmlx.so $(LibftPath)/libft.a -lSDL2 -lm
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ -I ./hdrs/

bonus: $(MY-B-OBJECTS)
	$(MAKE_N) $(MacroPath) -j
	$(MAKE_B) $(LibftPath)
	$(CC) -o $(NAME) $(CFLAGS) $(INCLUDES) $(MY-B-OBJECTS) $(MacroPath)/libmlx.so $(LibftPath)/libft.a -lSDL2 -lm

clean:
	$(MAKE_C) $(LibftPath)
	$(MAKE_C) $(MacroPath)
	$(RM) $(BUILD_DIR)
	@echo "\033[92mCleaned.\033[0m"

fclean: clean
	$(MAKE_F) $(MacroPath)
	$(MAKE_F) $(LibftPath)
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
