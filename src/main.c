/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 00:28:26 by srapin            #+#    #+#             */
/*   Updated: 2023/03/09 00:48:28 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int ac, char **av)
{
	t_img	img;
	t_img	back_img;
	t_app	app;

	parse_args(ac, av, &app);
	return (run_app(&app, av[1], &img, &back_img));
}
