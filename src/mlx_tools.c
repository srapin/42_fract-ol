/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 02:31:46 by srapin            #+#    #+#             */
/*   Updated: 2023/03/09 02:32:03 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	init_img(t_app *app, t_img *img)
{
	img->img = mlx_new_image(app->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_length), &(img->endian));
}

void	set_img(t_app *app)
{
	int		x;
	int		y;
	t_img	*save_img;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(app->back_img, x, y, get_pix_color(app, x, y));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(app->mlx_ptr, app->win_ptr, app->back_img->img, 0,
		0);
	save_img = app->img;
	app->img = app->back_img;
	app->back_img = save_img;
}

int	ft_close(t_app *app)
{
	if (!mlx_loop_end(app->mlx_ptr))
	{
		write(2, "Error when closing window\n", 26);
		mlx_destroy_window(app->mlx_ptr, app->win_ptr);
		return (0);
	}
	mlx_destroy_image(app->mlx_ptr, app->img->img);
	mlx_destroy_image(app->mlx_ptr, app->back_img->img);
	mlx_destroy_window(app->mlx_ptr, app->win_ptr);
	mlx_destroy_display(app->mlx_ptr);
	free(app->mlx_ptr);
	exit(0);
	return (1);
}

int	create_rgb(unsigned char r, unsigned char g, unsigned char b)
{
	t_color	c;

	c = (t_color){
		.r = r, .b = b, .g = g};
	return (c.hex);
}
