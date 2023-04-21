/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 00:09:56 by srapin            #+#    #+#             */
/*   Updated: 2023/03/08 23:51:26 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_complex	c_mult_c(t_complex z1, t_complex z2)
{
	return ((t_complex){
		.re = z1.re * z2.re - z1.im * z2.im,
		.im = 2 * z1.re * z2.im});
}

t_complex	c_plus_c(t_complex z1, t_complex z2)
{
	return ((t_complex){
		.re = z1.re + z2.re,
		.im = z1.im + z2.im});
}

t_complex	c_mult_i(t_complex z, int i)
{
	return ((t_complex){
		.re = z.re * i,
		.im = z.im * i});
}

t_complex	c_plus_i(t_complex z, int i)
{
	return ((t_complex){
		.re = z.re + i,
		.im = z.im});
}
