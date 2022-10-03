/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdemirci <kamil@kakbir.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 07:42:21 by pbondoer          #+#    #+#             */
/*   Updated: 2022/08/30 10:40:00 by kdemirci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include <fcntl.h>
#include <stdlib.h>

int	die(char *reason)
{
	ft_putendl(reason);
	return (1);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	t_mlx	*mlx;
	int		fd;

	if (argc < 2)
		return (die("error: not enough arguments"));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || !read_file(fd, &map))
		return (die("error: invalid file"));
	mlx = init(ft_strjoin("KAKBIR FDF -", argv[1]));
	if (mlx == NULL)
		return (die("error: mlx couldn't init"));
	mlx->map = map;
	render(mlx);
	mlx_key_hook(mlx->window, hook_keydown, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
