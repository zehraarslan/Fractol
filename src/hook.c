/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarslan <zarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:12:18 by zarslan           #+#    #+#             */
/*   Updated: 2022/09/02 10:52:27 by zarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook_color2(int keycode, t_fractol *data)
{
	if (keycode == 29)
		data->color = 7982541;
	else if (keycode == 27)
		data->color = 7982541;
	else if (keycode == 24)
		data->color = 7982541;
	else if (data->fractal == 1)
		key_hook_julia(keycode, data);
	return (1);
}

int	key_hook_color(int keycode, t_fractol *data)
{
	if (keycode == 18)
		data->color = 190701;
	else if (keycode == 19)
		data->color = 8021998;
	else if (keycode == 20)
		data->color = 1677216;
	else if (keycode == 21)
		data->color = 4882509;
	else if (keycode == 23)
		data->color = 16769543;
	else if (keycode == 22)
		data->color = 2354;
	else if (keycode == 26)
		data->color = 16728121;
	else if (keycode == 28)
		data->color = 6845745;
	else if (keycode == 25)
		data->color = 13361919;
	else
		key_hook_color2(keycode, data);
	return (1);
}

int	key_hook2(int keycode, t_fractol *data)
{
	if (keycode == 122)
	{
		fractal_reset(data);
		data->fractal = 1;
	}
	else if (keycode == 120)
	{	
		fractal_reset(data);
		data->fractal = 2;
	}
	else if (keycode == 99)
	{
		fractal_reset(data);
		data->fractal = 3;
	}
	else
		key_hook_color(keycode, data);
	fractal_draw(data);
	return (1);
}

int	key_hook(int keycode, t_fractol *data)
{
	if (keycode == 53)
		close_hook(data);
	if (keycode == 13 || keycode == 126)
		data->bit.gez_y += 0.5 * data->zoom;
	else if (keycode == 1 || keycode == 125)
		data->bit.gez_y -= 0.5 * data->zoom;
	else if (keycode == 0 || keycode == 123)
		data->bit.gez_x += 0.5 * data->zoom;
	else if (keycode == 2 || keycode == 124)
		data->bit.gez_x -= 0.5 * data->zoom;
	else if (keycode == 15)
		fractal_reset(data);
	else
		key_hook2(keycode, data);
	fractal_draw(data);
	return (1);
}

int	close_hook(t_fractol *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (1);
}
