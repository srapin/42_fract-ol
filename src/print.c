/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 05:35:20 by srapin            #+#    #+#             */
/*   Updated: 2023/03/20 19:07:54 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_bool	print_im_or_re_error(t_app *app)
{
	app->args_ok = false;
	ft_printf("[im=] and [re=] must be followed by a float");
	ft_printf("and are only available if fract_name is julia\n");
	return (false);
}

int	print_valid_args(void)
{
	ft_printf("./fractol fract_name [--help] [--cmd] ");
	ft_printf("[re=double] [im=double]\n");
	ft_printf("--cmd to print cmd during exectution\n");
	return (PARSE_ERROR);
}

int	print_usage(void)
{
	ft_printf("arrow to modify offset\n + and - to manage iteration\n");
	ft_printf("mouse click to change julia's parameter\n");
	ft_printf("c and v to change color\n n to change fractal\n");
	ft_printf("i to add or remove color intside fractale \n");
	ft_printf("o to add or remove color outside fractale \n");
	ft_printf("r to reset, zoom, ffset and max_iterations\n");
	return (PARSE_OPTION);
}
