/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdemirci <kamil@kakbir.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 05:33:42 by pbondoer          #+#    #+#             */
/*   Updated: 2022/09/01 16:23:43 by kdemirci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "fdf.h"

t_mlx	*mlxdel(t_mlx *mlx)
{
	if (mlx->window != NULL)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->cam != NULL)
		ft_memdel((void **)&mlx->cam);
	if (mlx->mouse != NULL)
		ft_memdel((void **)&mlx->mouse);
	if (mlx->image != NULL)
		del_image(mlx, mlx->image);
	ft_memdel((void **)&mlx);
	return (NULL);
}

t_mlx	*init(char *title)
{
	t_mlx	*mlx;

	mlx = ft_memalloc(sizeof(t_mlx));
	if (mlx == NULL)
		return (NULL);
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, WIN_WIDTH,
			WIN_HEIGHT, title);
	mlx->cam = ft_memalloc(sizeof(t_cam));
	mlx->mouse = ft_memalloc(sizeof(t_mouse));
		mlx->image = new_image(mlx);
	if (mlx->mlx == NULL || mlx->window == NULL || mlx->cam == NULL
		|| mlx->mouse == NULL
		|| mlx->image == NULL)
		return (mlxdel(mlx));
	mlx->cam->x = 0.5;
	mlx->cam->y = 0.5;
	mlx->cam->scale = 30;
	mlx->cam->offsetx = WIN_WIDTH / 2;
	mlx->cam->offsety = WIN_HEIGHT / 2;
	return (mlx);
}
