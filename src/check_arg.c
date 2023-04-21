/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 23:43:12 by srapin            #+#    #+#             */
/*   Updated: 2023/03/20 19:13:47 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_bool	check_option(t_app *app, char *arg)
{
	if (ft_strisequal(arg, "--cmd"))
		app->print_option = true;
	else if (ft_strisequal(arg, "--help"))
		app->print_valid = true;
	else
		return (false);
	return (true);
}

t_bool	check_const(t_app *app, char *arg)
{
	double	re;
	double	im;
	t_bool	flag;

	re = app->c.re;
	im = app->c.im;
	flag = false;
	if (ft_strnstr(arg, "re=", 3) == arg)
	{
		if (!ft_strisfloat(arg + 3 * sizeof(char)) || app->fract != JULIA)
			return (print_im_or_re_error(app));
		re = atof(arg + 3 * sizeof(char));
		flag = true;
	}
	if (ft_strnstr(arg, "im=", 3) == arg)
	{
		if (!ft_strisfloat(arg + 3 * sizeof(char)) || app->fract != JULIA)
			return (print_im_or_re_error(app));
		im = atof(arg + 3 * sizeof(char));
		flag = true;
	}
	app->c = (t_complex){.re = re, .im = im};
	return (flag);
}
