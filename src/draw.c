/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdemirci <kamil@kakbir.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 06:06:04 by pbondoer          #+#    #+#             */
/*   Updated: 2022/09/01 16:50:42 by kdemirci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"

int	clerp(int c1, int c2, double p)
{
	int	r;
	int	g;
	int	b;

	if (c1 == c2)
		return (c1);
	r = ft_lerpi((c1 >> 16) & 0xFF, (c2 >> 16) & 0xFF, p);
	g = ft_lerpi((c1 >> 8) & 0xFF, (c2 >> 8) & 0xFF, p);
	b = ft_lerpi(c1 & 0xFF, c2 & 0xFF, p);
	return (r << 16 | g << 8 | b);
}

int	line_process_point(t_mlx *mlx, t_line *l, t_vector *p1,
			t_vector *p2)
{
	double	percent;

	if (p1->x < 0 || p1->x >= WIN_WIDTH || p1->y < 0 || p1->y >= WIN_HEIGHT
		|| p2->x < 0 || p2->x >= WIN_WIDTH || p2->y < 0 || p2->y >= WIN_HEIGHT)
		return (1);
	if (l->dx > l->dy)
	{
		percent = (ft_ilerp((int)p1->x, (int)l->start.x, (int)l->stop.x));
	}
	else
		percent = ft_ilerp((int)p1->y, (int)l->start.y, (int)l->stop.y);
	image_set_pixel(mlx->image, (int)p1->x, (int)p1->y, clerp(p1->color,
			p2->color, percent));
	l->err2 = l->err;
	if (l->err2 > -l->dx)
	{
		l->err -= l->dy;
		p1->x += l->sx;
	}
	if (l->err2 < l->dy)
	{
		l->err += l->dx;
		p1->y += l->sy;
	}
	return (0);
}

void	line(t_mlx *mlx, t_vector p1, t_vector p2)
{
	t_line	line;

	p1.x = (int)p1.x;
	p2.x = (int)p2.x;
	p1.y = (int)p1.y;
	p2.y = (int)p2.y;
	line.start = p1;
	line.stop = p2;
	if (!lineclip(&p1, &p2, 0, 0))
		return ;
	line.dx = (int)ft_abs((int)p2.x - (int)p1.x);
	line.sx = linenumber(p1, p2);
	line.dy = (int)ft_abs((int)p2.y - (int)p1.y);
	line.sy = linenumber2(p1, p2);
	if (line.dx > line.dy)
		line.err = line.dx / 2;
	else
		line.err = -line.dy / 2;
	while (((int)p1.x != (int)p2.x || (int)p1.y != (int)p2.y))
		if (line_process_point(mlx, &line, &p1, &p2))
			break ;
}

void	render(t_mlx *mlx)
{
	int			x;
	int			y;
	t_vector	v;
	t_map		*map;

	map = mlx->map;
	clear_image(mlx->image);
	x = 0;
	while (x < map->width)
	{
		y = 0;
		while (y < map->height)
		{	
			v = project_vector(vector_at(map, x, y), mlx);
			if (x + 1 < map->width)
				line(mlx, v, project_vector(vector_at(map, x + 1, y), mlx));
			if (y + 1 < map->height)
				line(mlx, v, project_vector(vector_at(map, x, y + 1), mlx));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image->image, 0, 0);
}
