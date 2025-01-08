/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:52:08 by ricmanue          #+#    #+#             */
/*   Updated: 2024/09/19 15:57:42 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mlx_linux/mlx.h"
#include "X11/X.h"
#include "X11/keysym.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	void	*img;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	if(keycode == XK_Escape)
	{
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(0);
	}
	return (0);
}

int	ft_close(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

int main(void)
{

	char	*path;
	int		img_width;
	int		img_height;
	t_vars	vars;

	path = "test1(copy).xpm";
	bzero(&vars, sizeof(t_vars));
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 1000, "Hello World!");
	vars.img = mlx_xpm_file_to_image(vars.mlx, path, &img_width, &img_height);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 10, 10);
	mlx_hook(vars.win, DestroyNotify, NoEventMask, ft_close, &vars);
	mlx_hook(vars.win, KeyPress, KeyPressMask, key_hook, &vars);
	mlx_loop(vars.mlx);
}
