/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_managment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 00:01:45 by srapin            #+#    #+#             */
/*   Updated: 2023/04/21 04:15:29 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_bool	ft_strisint(char *str)
{
	t_bool	flag;
	int		i;

	i = 0;
	flag = true;
	if (!str)
		return (false);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			flag = false;
		i++;
	}
	return (flag);
}

t_bool	ft_strisfloat(char *str)
{
	t_bool	flag;
	t_bool	point;
	int		i;

	i = -1;
	flag = true;
	point = false;
	if (!str || !str[0])
		return (false);
	if (str[0] == '-')
		i++;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
		{
			if (str[i] == '.')
			{
				if (!point)
					point = true;
				else
					flag = false;
			}
			else
				flag = false;
		}
	}
	return (flag);
}

t_bool	ft_strisequal(char *s1, char *s2)
{
	if (!s1 && !s2)
		return (true);
	if (!s1 || !s2)
		return (false);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (false);
	if (!ft_strnstr(s1, s2, ft_strlen(s1)))
		return (false);
	return (true);
}

t_bool	fract_name(t_app *app, char *arg)
{
	t_fract	ret;

	ret = app->fract;
	if (ft_strisequal("julia", arg))
		app->fract = JULIA;
	else if (ft_strisequal("mandelbrot", arg))
		app->fract = MANDELBROT;
	else if (ft_strisequal("burning_ship", arg))
		app->fract = BURNING_SHIP;
	else
		return (false);
	if (!(ret == NONE || ret == app->fract))
		app->args_ok = false;
	return (true);
}

void	parse_args(int ac, char **av, t_app *app)
{
	int		i;
	t_bool	flag;

	i = 1;
	init_app_parameters(app);
	app->args_ok = true;
	while (i < ac)
	{
		flag = false;
		flag = fract_name(app, av[i]);
		if (!flag)
			flag = check_option(app, av[i]);
		if (!flag)
			flag = check_const(app, av[i]);
		if (!flag)
			app->args_ok = false;
		if (!app->args_ok)
			return ;
		i++;
	}
	if (app->fract == NONE)
		app->args_ok = false;
}
/*
void	parse_args(int ac, char **av, t_app *app)
{
	init_app_parameters(app);
	app->args_ok = true;
	check_len(ac, app);
	if (!app->args_ok)
		return ;
	check_option(ac, av, app);
	if (!app->args_ok)
		return ;
	check_name(ac, av, app);
	if (!app->args_ok)
		return ;
	check_color(2, ac, av, app);
	return ;
}
*/