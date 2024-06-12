/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalliez <ehalliez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 01:47:08 by ehalliez          #+#    #+#             */
/*   Updated: 2024/06/10 16:53:31 by ehalliez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

# include "../libs/MacroLibX/includes/mlx.h"
# include "../libs/libft/libft.h"
# include "stdbool.h"
# include <math.h>

/*---------- GENERAL OPTION ----------*/

# define WIDTH 1280
# define HEIGHT 900

/*----------- MENU OPTIONS -----------*/

# define HOVER_WIDTH 600
# define HOVER_HEIGHT 80
# define TEXT_COLOR 0xFFFFFFFF
# define HOVER_COLOR 0x96969666

/*----------- MENU OPTIONS -----------*/

# define HOVER_WIDTH 600
# define HOVER_HEIGHT 80
# define TEXT_COLOR 0xFFFFFFFF
# define HOVER_COLOR 0x96969666

/*----------- RAYS  OPTION -----------*/

# define RAY_COUNT 1280

/*--------------- KEY ---------------*/

# define FORWARD 26
# define BACKWARD 22
# define LEFT 4
# define RIGHT 7
# define ARROW_UP 82
# define ARROW_DOWN 81
# define ARROW_LEFT 80
# define ARROW_RIGHT 79
# define SHIFT 225
# define SPACE 49
# define LEFT_CLICK 1

/*--------- MINI-MAP OPTION ---------*/

# define TILE_SIZE 32
# define PLAYER_SIZE 8
# define WALL_COLOR 0xCC2E2E2E
# define PLAYER_COLOR 0xCC000000
# define GROUND_COLOR 0xCCA9A9A9
# define GAME_GROUND_COLOR 0xFF808080
# define CEILING_COLOR 0xFF1F92E0
# define PLAYER_CASE_COLOR 0xFFD69AC8
# define RAY_COLOR 0xFF056B90
# define X_POS 25
# define Y_POS 25
# define PLAYER_SIZE_MINIMAP 4
# define MINIMAP_WIDTH 5
# define MINIMAP_HEIGHT 5
# define MARGIN_X 50
# define MARGIN_Y 50
# define TILE_BORDER_COLOR 0x88000000
# define PLAYER_BORDER_COLOR 0xFF000000
# define TRANSPARENCY 0x88000000

/*------------- UTILS  -------------*/

# define X 0
# define Y 1
# define WALL '1'
# define GROUND '0'
# define PLAYER 'P'
# define PI 3.1415926535
# define FOV 1.17079632679 // PI / 2

/*------------- IMAGES  -------------*/

# define BASE 0 // GROUND CEILING WALLS
# define PLAYER_VIEW 1 // ALL PLAYER COMPONENT
# define MINIMAP 2 // MINIMAP
# define MENU 3 // MENU
# define S_BACK 4 // SETTINGS_BACKGROUND
# define CHECKED 5 // SETTINGS_BACKGROUND
# define UNCHECKED 6 // SETTINGS_BACKGROUND
# define M_BACK 7 // MAIN_MENU_BACKGROUND
# define M_BACK_2 8 // MAIN_MENU_BACKGROUND_2

/*------------ STRUCTURE -----------*/

typedef enum s_display {
	MAIN_MENU,
	SETTINGS,
	GAME
}	t_display;

typedef enum s_direction {
	NORTH,
	SOUTH,
	EAST,
	WEST
}	t_direction;

typedef struct s_parse {
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		floor_color;
	int		sky_color;
	int		check_floor;
	int		check_sky;
	int		check;
	int		count_line_map;
	int		has_player;
}	t_parse;

typedef struct s_rays {
	float	ray_dir[2];
	float	xy[2];
	float	delta_dist_xy[2];
	float	side_dist_xy[2];
	int		map_xy[2];
	int		step_xy[2];
	float	perp_wall_dist;
	int		side;
}	t_rays;

typedef struct s_game_map {
	char	**map;
	double	player_pos[2];
	double	player_dir[2];
	float	player_angle;
	int		position[2];
	int		map_height;
	double	*distances;
	int		minimap_width;
	double	*x_ray;
	double	*y_ray;
	int		*ray_side;
	int		*ray_orientation;
	int		dynamic_ray_count;
	t_rays	rays;
}	t_game_map;

typedef struct s_settings {
	int		width;
	int		height;
	float	sensibility;
	float	fov;
	int		n_width;
	int		n_height;
	int		n_sensibility;
	float	n_fov;
	int		d_fps;
	int		d_date;
	int		d_cardinal;
}	t_settings;

typedef struct s_textures {
	void	*texture;
	int		width;
	int		height;
}	t_textures;

typedef struct s_sprite {
	void		*heart[6];
	void		*stamina[14];
	t_textures	*wall[5];
	void		*weapon[5];
	void		*slider[4];
	void		*button[6];
	int			bullets;
}	t_sprite;

typedef struct s_mlx_component {
	void		*mlx;
	void		*win;
	bool		mouse_left;
	int			player_start_angle;
	int			display;
	void		*img[9];
	char		input[500];
	int			mouse_right;
	float		speed;
	int			pressed;
	double		stamina;
	float		slowed;
	t_game_map	*map;
	t_parse		*parse;
	t_sprite	*sprite;
	t_settings	*settings;
}	t_cub;

#endif