/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/18 12:49:31 by anonymous     #+#    #+#                 */
/*   Updated: 2020/10/12 15:51:40 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef	struct	s_map_data
{
	int			index;
	int			res_x;
	int			res_y;
	char		*n_path;
	char		*s_path;
	char		*e_path;
	char		*w_path;
	char		*spr_path;
	int			floor;
	int			ceiling;
	int			c_check;
	int			f_check;
	int			*map_x;
	int			map_y;
	int			**map;
	int			**flood;
	int			spawn_loc_x;
	int			spawn_loc_y;
	char		sp_or;
	int			screenshot;
}				t_map_data;

typedef struct	s_mlx_data
{
	void		*ptr;
	void		*wdw;
	void		*new_img;
	void		*old_img;
	char		*addr;
	int			bpp;
	int			ls;
	int			end;
	int			render;
}				t_mlx_data;

typedef	struct	s_move_data
{
	int			forward;
	int			backward;
	int			left;
	int			right;
	int			rot_l;
	int			rot_r;
}				t_move_data;

typedef struct	s_calc
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		cam_x;
	double		ray_x;
	double		ray_y;
	double		dist_x;
	double		dist_y;
	double		delta_x;
	double		delta_y;
	double		*dist_wall;
	double		wall_x;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			x;
	int			wall_or;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			wall_height;
	int			tex_x;
	int			tex_y;
	double		step;
	double		tex_pos;
}				t_calc;

typedef struct	s_tex
{
	void		*tex_s;
	char		*addr_s;
	int			bpp_s;
	int			ls_s;
	int			end_s;
	int			y_s;
	int			x_s;
	void		*tex_w;
	char		*addr_w;
	int			bpp_w;
	int			ls_w;
	int			end_w;
	int			y_w;
	int			x_w;
	void		*tex_n;
	char		*addr_n;
	int			bpp_n;
	int			ls_n;
	int			end_n;
	int			y_n;
	int			x_n;
	void		*tex_e;
	char		*addr_e;
	int			bpp_e;
	int			ls_e;
	int			end_e;
	int			y_e;
	int			x_e;
	void		*tex_spr;
	char		*addr_spr;
	int			bpp_spr;
	int			ls_spr;
	int			end_spr;
	int			y_spr;
	int			x_spr;
}				t_tex;

typedef struct	s_spr
{
	double		**sprite;
	double		*distance;
	double		sprite_x;
	double		sprite_y;
	double		inv;
	double		transform_x;
	double		transform_y;
	int			screen_x;
	int			height;
	int			width;
	int			start_y;
	int			end_y;
	int			start_x;
	int			end_x;
	int			amount;
	int			stripe;
	int			tex_x;
	int			tex_y;
}				t_spr;

typedef struct	s_meta_data
{
	t_map_data	map;
	t_mlx_data	mlx;
	t_move_data	move;
	t_calc		calc;
	t_tex		tex;
	t_spr		spr;
}				t_meta_data;

void			ft_putstr(char *s);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *str);
int				ft_atoi(const char *str, int i);
void			argument_check(int ac, char **av, t_map_data *map);
void			read_data(t_map_data *map_data, char *map_path);
void			parse_data(t_map_data *map_data, char *map);
void			get_res(t_map_data *map_data, char *map);
void			get_path(t_map_data *map_data, char *map, char type);
void			get_color(t_map_data *map_data, char *map, char type);
void			get_map(t_map_data *map_data, char *map);
void			check_map(t_map_data *map_data);
void			fill_spawn(t_meta_data *meta);
void			fill_tex(t_tex *tex, t_mlx_data *mlx, t_map_data *map);
void			fill_spr(t_spr *spr, t_map_data *map);
t_meta_data		init_meta_data(void);
t_tex			init_tex(void);
t_spr			init_spr(void);
t_move_data		init_move(void);
t_mlx_data		init_mlx(void);
int				keypress_hook(int keycode, t_meta_data *meta);
int				keyrelease_hook(int keycode, t_meta_data *meta);
int				exit_hook(t_meta_data *meta);
int				image(t_meta_data *meta);
void			image_calc(t_meta_data *meta);
void			draw_sprite(t_meta_data *meta_data);
void			create_sprite(t_meta_data *m, t_spr *spr);
void			dda(t_map_data *map, t_calc *calc);
void			move_forward(t_calc *calc, t_map_data *map, t_move_data *move);
void			move_backward(t_calc *calc, t_map_data *map, t_move_data *move);
void			move_left(t_calc *calc, t_map_data *map, t_move_data *move);
void			move_right(t_calc *calc, t_map_data *map, t_move_data *move);
void			rotate_left(t_calc *calc);
void			rotate_right(t_calc *calc);
int				skip_empty_space(int i, char *str);
void			screenshot(t_meta_data *meta);
void			on_error();
#endif
