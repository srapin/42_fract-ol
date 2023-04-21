/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_annex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 23:48:16 by srapin            #+#    #+#             */
/*   Updated: 2023/03/08 23:49:41 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	get_blue_color(int iter, int x, int y, t_app *app)
{
	if (app->color_out && iter)
		return (create_rgb(0, (unsigned char){iter * 1000} / 4, iter * 1000));
	if (app->color_in && !iter)
		return (create_rgb(0, 0, 1000 * (x * y)));
	return (create_rgb(0, 0, 0));
}

int	get_green_color(int iter, int x, int y, t_app *app)
{
	if (app->color_out && iter)
		return (create_rgb(0, iter * 1000, 0));
	if (app->color_in && !iter)
		return (create_rgb(0, 1000 * (x * y), 0));
	return (create_rgb(0, 0, 0));
}

int	get_red_color(int iter, int x, int y, t_app *app)
{
	if (app->color_out && iter)
		return (create_rgb(iter * 1000, 0, 0));
	if (app->color_in && !iter)
		return (create_rgb(1000 * (x * y), 0, 0));
	return (create_rgb(0, 0, 0));
}

int	get_white_color(int iter, int x, int y, t_app *app)
{
	if (app->color_out && iter)
		return (create_rgb(iter * 1000, iter * 1000, iter * 1000));
	if (app->color_in && !iter)
		return (create_rgb(1000 * (x * y), 1000 * (x * y), 1000 * (x * y)));
	return (create_rgb(0, 0, 0));
}

int	get_black_color(int iter, int x, int y, t_app *app)
{
	if (app->color_out && iter)
		return (create_rgb(iter * 10, iter * 10, iter * 10));
	if (app->color_in && !iter)
		return (create_rgb(1000 * (x * y), 1000 * (x * y), 1000 * (x * y)));
	return (create_rgb(0, 0, 0));
}
