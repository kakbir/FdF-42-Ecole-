/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdemirci <kamil@kakbir.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 05:33:43 by pbondoer          #+#    #+#             */
/*   Updated: 2022/08/30 10:39:00 by kdemirci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

int	hook_keydown(int key, t_mlx *mlx)
{
	(void)mlx;
	if (key == 53)
		exit(EXIT_SUCCESS);
	else if (key == 126)
		mlx->cam->offsety -= 10;
	else if (key == 124)
		mlx->cam->offsetx += 10;
	else if (key == 123)
		mlx->cam->offsetx -= 10;
	else if (key == 125)
		mlx->cam->offsety += 10;
	else if (key == 27)
		mlx->cam->scale += 5;
	else if (key == 24)
		mlx->cam->scale -= 5;
	else if (key == 13)
		mlx->cam->x -= 0.1;
	else if (key == 2)
		mlx->cam->y -= 0.1;
	else if (key == 1)
		mlx->cam->x += 0.1;
	else if (key == 0)
		mlx->cam->y += 0.1;
	render(mlx);
	return (0);
}
