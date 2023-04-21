/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 00:22:48 by srapin            #+#    #+#             */
/*   Updated: 2023/03/20 19:14:44 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_app_parameters(t_app *app)
{
	app->args_ok = true;
	app->print_option = false;
	app->color_tone = white;
	app->fract = NONE;
	app->max_iter = 20;
	app->zoom = 1.0;
	app->x_offset = BASE_OFFSET;
	app->y_offset = BASE_OFFSET;
	app->color_out = true;
	app->color_in = false;
	app->args_ok = true;
	app->print_option = false;
	app->print_valid = false;
	app->c = (t_complex){.re = 0.321, .im = 0.0};
}

int	init_app(t_app *app, t_img *img, t_img *back_img, char *name)
{
	if (app->print_option)
		print_usage();
	if (!app->args_ok || app->print_valid)
	{
		print_valid_args();
		if (!app->args_ok)
			return (PARSE_ERROR);
	}
	app->mlx_ptr = mlx_init();
	if (!app->mlx_ptr)
		return (MLX_ERROR);
	app->win_ptr = mlx_new_window(app->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			name);
	if (!app->win_ptr)
	{
		ft_close(app);
		return (0);
	}
	init_img(app, img);
	app->img = img;
	init_img(app, back_img);
	app->back_img = back_img;
	add_hooks(app);
	return (OK);
}

int	run_app(t_app *app, char *name, t_img *img, t_img *back_img)
{
	int	init_ret;

	init_ret = init_app(app, img, back_img, name);
	if (init_ret)
		return (init_ret);
	set_img(app);
	mlx_loop(app->mlx_ptr);
	return (OK);
}
