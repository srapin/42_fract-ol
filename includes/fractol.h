/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 22:31:54 by srapin            #+#    #+#             */
/*   Updated: 2023/03/20 19:12:27 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libs/libft/ft_printf.h"
# include "../libs/minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define MLX_ERROR 1
# define PARSE_ERROR 2
# define PARSE_OPTION 1
# define OK 0
# define WINDOW_WIDTH 1400
# define WINDOW_HEIGHT 1400
# define COMPLEX_WIDTH 4
# define COMPLEX_HEIGHT 4
# define BASE_OFFSET -2

typedef union u_color
{
	int					hex;
	struct
	{
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
		unsigned char	t;
	};
}						t_color;

typedef enum e_fract
{
	JULIA,
	MANDELBROT,
	BURNING_SHIP,
	NONE
}						t_fract;

typedef enum e_color_tone
{
	rg,
	rb,
	bg,
	red,
	green,
	blue,
	black,
	white,
}						t_color_tone;

typedef enum e_bool
{
	false,
	true
}						t_bool;

typedef struct s_complex
{
	double				re;
	double				im;
}						t_complex;

typedef struct s_img
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}						t_img;

typedef struct s_app
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					max_iter;
	t_complex			c;
	double				zoom;
	double				x_offset;
	double				y_offset;
	t_img				*img;
	t_img				*back_img;
	t_color_tone		color_tone;
	t_fract				fract;
	t_bool				color_out;
	t_bool				color_in;
	t_bool				args_ok;
	t_bool				print_option;
	t_bool				print_valid;
}						t_app;

//app.c
void					init_app_parameters(t_app *app);
int						init_app(t_app *app, t_img *img, t_img *back_img,
							char *name);
int						run_app(t_app *app, char *name, t_img *img,
							t_img *back_img);

//args_managment.c
t_bool					ft_strisint(char *str);
t_bool					ft_strisfloat(char *str);
t_bool					ft_strisequal(char *s1, char *s2);
void					parse_args(int ac, char **av, t_app *app);

//check_arg.c
t_bool					check_option(t_app *app, char *arg);
t_bool					check_const(t_app *app, char *arg);

//color_annex.c
int						get_blue_color(int iter, int x, int y, t_app *app);
int						get_green_color(int iter, int x, int y, t_app *app);
int						get_red_color(int iter, int x, int y, t_app *app);
int						get_black_color(int iter, int x, int y, t_app *app);
int						get_white_color(int iter, int x, int y, t_app *app);

//color.c
int						get_color(int iter, int x, int y, t_app *app);
int						get_pix_color(t_app *app, int x, int y);

//complex_tols.c
t_complex				c_mult_c(t_complex z1, t_complex z2);
t_complex				c_plus_c(t_complex z1, t_complex z2);
t_complex				c_mult_i(t_complex z, int i);
t_complex				c_plus_i(t_complex z, int i);

//convert.c
double					ft_atof(char *nptr);
t_complex				get_complex_pos(t_app *app, int x, int y);

//fractol.c
int						get_iter(t_app *app, t_complex z);

//hooks_no_event.c

int						handle_no_event(void);

//hooks.c
void					add_hooks(t_app *app);

//main.c
int						main(int ac, char **av);

//mlx_tools.c
int						create_rgb(unsigned char r, unsigned char g,
							unsigned char b);
void					my_mlx_pixel_put(t_img *img, int x, int y, int color);
int						ft_close(t_app *data);
void					set_img(t_app *app);
void					init_img(t_app *app, t_img *img);

//print.c
t_bool					print_im_or_re_error(t_app *app);
int						print_valid_args(void);
int						print_usage(void);

#endif