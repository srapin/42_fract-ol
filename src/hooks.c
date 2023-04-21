/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 00:10:10 by srapin            #+#    #+#             */
/*   Updated: 2023/03/20 19:03:21 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	handle_keypress_helper(int keysym, t_app *app)
{
	if (keysym == 0x003d)
		app->max_iter += 10;
	else if (keysym == 0x002d)
	{
		if (app->max_iter > 0)
			app->max_iter -= 10;
	}
	else if (keysym == XK_Up)
		app->y_offset += 0.2 / app->zoom;
	else if (keysym == XK_Down)
		app->y_offset -= 0.2 / app->zoom;
	else if (keysym == XK_Left)
		app->x_offset += 0.2 / app->zoom;
	else if (keysym == XK_Right)
		app->x_offset -= 0.2 / app->zoom;
	else if (keysym == XK_i)
		app->color_in = 1 - app->color_in;
	else if (keysym == XK_o)
		app->color_out = 1 - app->color_out;
}

void	handle_keypress_helper_2(int keysym, t_app *app)
{
	if (keysym == XK_r)
	{
		app->zoom = 1.0;
		app->x_offset = BASE_OFFSET;
		app->y_offset = BASE_OFFSET;
		app->max_iter = 20;
	}
	if (keysym == XK_c)
	{
		if (app->color_tone == 7)
			app->color_tone = 0;
		else
			app->color_tone++;
	}
	if (keysym == XK_v)
	{
		if (app->color_tone == 0)
			app->color_tone = 7;
		else
			app->color_tone--;
	}
}

int	handle_keypress(int keysym, t_app *app)
{
	handle_keypress_helper(keysym, app);
	handle_keypress_helper_2(keysym, app);
	if (keysym == XK_n)
	{
		if (app->fract == 2)
		{
			app->fract = JULIA;
			app->c = (t_complex){.re = 0.39, .im = 0.6};
		}
		else
			app->fract++;
	}
	if (keysym == XK_r)
	{
		app->zoom = 1.0;
		app->x_offset = BASE_OFFSET;
		app->y_offset = BASE_OFFSET;
		app->max_iter = 20;
	}
	set_img(app);
	if (keysym == XK_Escape)
		ft_close(app);
	return (OK);
}

int	handle_mouse(int keysym, int x, int y, t_app *app)
{
	if (keysym == 1 && app->fract == JULIA)
	{
		app->c = get_complex_pos(app, x, y);
	}
	if (keysym == 4)
	{
		app->x_offset += ((COMPLEX_WIDTH * x) / (app->zoom * WINDOW_WIDTH))
			- ((COMPLEX_WIDTH * x) / (app->zoom * 1.2 * WINDOW_WIDTH));
		app->y_offset += ((COMPLEX_HEIGHT * y) / (app->zoom * WINDOW_HEIGHT))
			- ((COMPLEX_HEIGHT * y) / (app->zoom * 1.2 * WINDOW_HEIGHT));
		app->zoom *= 1.2;
	}
	else if (keysym == 5)
	{
		app->x_offset += ((COMPLEX_WIDTH * x) / (app->zoom * WINDOW_WIDTH))
			- ((COMPLEX_WIDTH * x) / ((app->zoom / 1.2) * WINDOW_WIDTH));
		app->y_offset += ((COMPLEX_HEIGHT * y) / (app->zoom * WINDOW_HEIGHT))
			- ((COMPLEX_HEIGHT * y) / ((app->zoom / 1.2) * WINDOW_HEIGHT));
		app->zoom /= 1.2;
	}
	set_img(app);
	return (keysym);
}

void	add_hooks(t_app *app)
{
	mlx_loop_hook(app->mlx_ptr, &handle_no_event, app);
	mlx_hook(app->win_ptr, KeyPress, KeyPressMask, &handle_keypress, app);
	mlx_hook(app->win_ptr, 33, 1L << 17, ft_close, app);
	mlx_mouse_hook(app->win_ptr, &handle_mouse, app);
}
