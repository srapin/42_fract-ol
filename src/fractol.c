/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 22:11:52 by srapin            #+#    #+#             */
/*   Updated: 2023/02/27 19:00:5 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	get_iter(t_app *app, t_complex z)
{
	int	iter;

	iter = 0;
	while (iter < app->max_iter)
	{
		if (app->fract == BURNING_SHIP)
			z = (t_complex){.re = fabs(z.re), .im = fabs(z.im)};
		z = c_mult_c(z, z);
		z = c_plus_c(z, app->c);
		iter++;
		if (z.im * z.im + z.re * z.re >= COMPLEX_HEIGHT)
			return (iter);
	}
	return (0);
}
