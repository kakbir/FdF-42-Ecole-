/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdemirci <kamil@kakbir.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 08:04:43 by pbondoer          #+#    #+#             */
/*   Updated: 2022/09/01 17:53:31 by kdemirci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

int	linenumber(t_vector p1, t_vector p2)
{
	if ((int)p1.x < (int)p2.x)
		return (1);
	else
		return (-1);
}

int	linenumber2(t_vector p1, t_vector p2)
{
	if ((int)p1.y < (int)p2.y)
		return (1);
	else
		return (-1);
}

t_vector	rotate(t_vector p, t_cam *r)
{
	t_vector	v;
	double		x;
	double		y;
	double		z;

	x = p.x;
	z = p.z;
	v.x = cos(r->y) * x + sin(r->y) * z;
	v.z = -sin(r->y) * x + cos(r->y) * z;
	y = p.y;
	z = v.z;
	v.y = cos(r->x) * y - sin(r->x) * z;
	v.z = sin(r->x) * y + cos(r->x) * z;
	v.color = p.color;
	return (v);
}
