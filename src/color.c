/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 00:09:51 by srapin            #+#    #+#             */
/*   Updated: 2023/03/08 23:50:30 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	get_rg_color(int iter, int x, int y, t_app *app)
{
	if (app->color_out && iter)
		return (create_rgb(iter * 100, iter * 100, 0));
	if (app->color_in && !iter)
		return (create_rgb(1000 * (x * y), 1000 * (x * y), 0));
	return (create_rgb(0, 0, 0));
}

int	get_rb_color(int iter, int x, int y, t_app *app)
{
	if (app->color_out && iter)
		return (create_rgb(iter * 10, 0, iter * 10));
	if (app->color_in && !iter)
		return (create_rgb(1000 * (x * y), 0, 1000 * (x * y)));
	return (create_rgb(0, 0, 0));
}

int	get_bg_color(int iter, int x, int y, t_app *app)
{
	if (app->color_out && iter)
		return (create_rgb(0, iter * 10, iter * 10));
	if (app->color_in && !iter)
		return (create_rgb(0, 1000 * (x * y), 1000 * (x * y)));
	return (create_rgb(0, 0, 0));
}

int	get_color(int iter, int x, int y, t_app *app)
{
	if (app->color_tone == rb)
		return (get_rb_color(iter, x, y, app));
	if (app->color_tone == rg)
		return (get_rg_color(iter, x, y, app));
	if (app->color_tone == bg)
		return (get_bg_color(iter, x, y, app));
	if (app->color_tone == blue)
		return (get_blue_color(iter, x, y, app));
	if (app->color_tone == green)
		return (get_green_color(iter, x, y, app));
	if (app->color_tone == red)
		return (get_red_color(iter, x, y, app));
	if (app->color_tone == white)
		return (get_white_color(iter, x, y, app));
	return (get_black_color(iter, x, y, app));
}

int	get_pix_color(t_app *app, int x, int y)
{
	int			iter;
	t_complex	z;

	if (app->fract == JULIA)
	{
		z = get_complex_pos(app, x, y);
	}
	else
	{
		z = (t_complex){.im = 0.0, .re = 0.0};
		app->c = get_complex_pos(app, x, y);
	}
	iter = get_iter(app, z);
	return (get_color(iter, x, y, app));
}
