/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 00:10:01 by srapin            #+#    #+#             */
/*   Updated: 2023/03/18 23:27:07 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	ft_atof(char *nptr)
{
	int		i;
	int		neg;
	double	dec;
	int		number;

	number = ft_atoi(nptr);
	if (ft_strisint(nptr))
		return (number);
	i = ft_strlen(nptr) - 1;
	dec = 0.0;
	neg = 1;
	if (!nptr)
		return (0.0);
	if (number < 0)
		neg = -1;
	while (i >= 0 && ft_isdigit(nptr[i]))
	{
		dec = dec / 10 + (nptr[i] - 48);
		i--;
	}
	return (number + neg * dec);
}

t_complex	get_complex_pos(t_app *app, int x, int y)
{
	double	re;
	double	im;

	re = ((COMPLEX_WIDTH * x) / (app->zoom * WINDOW_WIDTH)) + app->x_offset;
	im = ((COMPLEX_HEIGHT * y) / (app->zoom * WINDOW_HEIGHT)) + app->y_offset;
	return ((t_complex){
		.re = re,
		.im = im});
}
