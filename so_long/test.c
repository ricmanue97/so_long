/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:52:08 by ricmanue          #+#    #+#             */
/*   Updated: 2024/08/29 14:34:27 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



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
	if(keycode == XK_a)
	{
		mlx_clear_window(vars->mlx, vars->win);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		 vars->x_point = vars->x_point - vars->img_width, vars->y_point);
	}

	if(keycode == XK_w)
	{
		mlx_clear_window(vars->mlx, vars->win);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		 vars->x_point, vars->y_point = vars->y_point - vars->img_height);
	}
	if(keycode == XK_d)
	{
		mlx_clear_window(vars->mlx, vars->win);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		 vars->x_point = vars->x_point + vars->img_width, vars->y_point);
	}
	if(keycode == XK_s)
	{
		mlx_clear_window(vars->mlx, vars->win);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		 vars->x_point, vars->y_point = vars->y_point + vars->img_height);
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
	t_vars	vars;


	vars.y_point = 0;
	vars.x_point = 0;
	path = "./floor1.xpm";
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello World!");
	vars.img = mlx_xpm_file_to_image(vars.mlx, path, &vars.img_width, &vars.img_height);
	while (vars.x_point < 1920)
	{
		vars.y_point = 0;
		while(vars.y_point < 1080)
		{
			mlx_put_image_to_window(vars.mlx, vars.win, vars.img, vars.x_point, vars.y_point);
			vars.y_point = vars.y_point + vars.img_width;
		}
		mlx_put_image_to_window(vars.mlx, vars.win, vars.img, vars.x_point, vars.y_point);
		vars.x_point = vars.x_point + vars.img_width;
	}
	mlx_hook(vars.win, DestroyNotify, NoEventMask, ft_close, &vars);
	mlx_hook(vars.win, KeyPress, KeyPressMask, key_hook, &vars);
	mlx_loop(vars.mlx);
}
//hook serve para registar keystrokes
/* typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!\n");
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
} */

