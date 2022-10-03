/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdemirci <kamil@kakbir.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 23:59:07 by pbondoer          #+#    #+#             */
/*   Updated: 2022/09/01 16:51:55 by kdemirci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIN_WIDTH			1280	// camin x boyutu
# define WIN_HEIGHT			720		// camin y boyutu

typedef struct		s_cam
{
	double		offsetx;
	double		offsety;
	double		x;	// 0.5
	double		y;	// 0.5
	int			scale; //kamera yakinligi
	double		**matrix;
}					t_cam;



typedef struct		s_vector
{
	double		x;
	double		y;
	double		z;
	int			color;
}					t_vector; //!!!



typedef struct		s_map
{
	int			width;		// mapin genislik (Argüman olarak gönderilen mapten aldığı boyut) 
	int			height;		// mapin yukseklik (Argüman olarak gönderilen mapten aldığı boyut) 
	int			depth_min;	//min_bolum
	int			depth_max;	//max_bolum
	t_vector	**vectors;	
}					t_map;


 
typedef struct		s_mouse
{
	char		isdown;
	int			x;
	int			y;
	int			lastx;
	int			lasty;
}					t_mouse;




typedef struct		s_image
{
	void		*image;
	char		*ptr;
	int			bpp;
	int			stride;
	int			endian;
}					t_image;



typedef struct		s_mlx
{
	void		*mlx;
	void		*window;
	t_image		*image;
	t_map		*map;
	t_cam		*cam;
	t_mouse		*mouse;
	double		**zbuf;
}					t_mlx;



typedef struct		s_line
{
	t_vector	start;
	t_vector	stop;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			err2;
}					t_line;
int					read_file(int fd, t_map **map);
t_vector			*get_vector(int x, int y, char *str);
t_map				*get_map(int width, int height);
t_mlx				*init(char *title);
void				render(t_mlx *mlx);
t_vector			rotate(t_vector p, t_cam *r);
t_vector			vector_at(t_map *map, int x, int y);
t_vector			project_vector(t_vector p, t_mlx *mlx);
int					hook_keydown(int key, t_mlx *mlx);
void				image_set_pixel(t_image *image, int x, int y, int color);
void				clear_image(t_image *image);
int					lineclip(t_vector *p1, t_vector *p2, int r1, int r2);
t_image				*new_image(t_mlx *mlx);
t_image				*del_image(t_mlx *mlx, t_image *img);
void				fill_colors(t_map *m);
int					linenumber(t_vector p1, t_vector p2);
int					linenumber2(t_vector p1, t_vector p2);
int					clerp(int c1, int c2, double p);
#endif