/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarslan <zarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 01:13:57 by zarslan           #+#    #+#             */
/*   Updated: 2022/09/02 10:53:48 by zarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fractal_condition(t_fractol *data)
{
	if (data->bit.iter < 100)
		my_mlx_pixel_put(&data->img, data->bit.x, data->bit.y, \
			data->bit.iter * data->color);
	else
		my_mlx_pixel_put(&data->img, data->bit.x, data->bit.y, 0x00000000);
	return (1);
}

void	julia(t_fractol *data)
{
	data->bit.y = -1;
	while (++data->bit.y < HEIGHT)
	{
		data->bit.x = -1;
		while (++data->bit.x < WIDTH)
		{
			data->bit.zx = ((-2 * data->zoom) + (data->bit.x_p / 5) + \
				data->bit.x * 4 * data->zoom / WIDTH) + data->bit.gez_x;
			data->bit.zy = ((-2 * data->zoom) + (data->bit.y_p / 5) + \
				data->bit.y * 4 * data->zoom / HEIGHT) + data->bit.gez_y;
			data->bit.iter = 0;
			while (++data->bit.iter < 100 && (data->bit.zx * data->bit.zx + \
				data->bit.zy * data->bit.zy) <= 4)
			{
				data->bit.zx_new = data->bit.zx * data->bit.zx - \
					data->bit.zy * data->bit.zy;
				data->bit.zy = 2 * data->bit.zx * data->bit.zy + data->bit.cy;
				data->bit.zx = data->bit.zx_new + data->bit.cx;
			}
			fractal_condition(data);
		}
	}
}

void	mandelbrot(t_fractol *data)
{
	data->bit.y = -1;
	while (++data->bit.y < HEIGHT)
	{
		data->bit.x = -1;
		while (++data->bit.x < WIDTH)
		{
			data->bit.zx = 0;
			data->bit.zy = 0;
			data->bit.cx = ((-2 * data->zoom) + (data->bit.x_p / 5) + \
				data->bit.x * 4 * data->zoom / WIDTH) + data->bit.gez_x;
			data->bit.cy = ((-2 * data->zoom) + (data->bit.y_p / 5) + \
				data->bit.y * 4 * data->zoom / HEIGHT) + data->bit.gez_y;
			data->bit.iter = 0;
			while (++data->bit.iter < 100 && (data->bit.zx * data->bit.zx) + \
				(data->bit.zy * data->bit.zy) <= 4)
			{
				data->bit.zx_new = data->bit.zx * data->bit.zx - \
					data->bit.zy * data->bit.zy;
				data->bit.zy = 2 * data->bit.zx * data->bit.zy + data->bit.cy;
				data->bit.zx = data->bit.zx_new + data->bit.cx;
			}
			fractal_condition(data);
		}
	}
}

void	burningship(t_fractol *data)
{
	data->bit.y = -1;
	while (++data->bit.y < HEIGHT)
	{
		data->bit.x = -1;
		while (++data->bit.x < WIDTH)
		{
			data->bit.zx = 0;
			data->bit.zy = 0;
			data->bit.cx = ((-2 * data->zoom) + (data->bit.x_p / 5) + \
				data->bit.x * 4 * data->zoom / WIDTH) + data->bit.gez_x;
			data->bit.cy = ((-2 * data->zoom) + (data->bit.y_p / 5) + \
				data->bit.y * 4 * data->zoom / HEIGHT) + data->bit.gez_y;
			data->bit.iter = 0;
			while (++data->bit.iter < 100 && ((data->bit.zx * data->bit.zx) + \
				(data->bit.zy * data->bit.zy) <= 4))
			{
				data->bit.zx_new = data->bit.zx * data->bit.zx - \
					data->bit.zy * data->bit.zy;
				data->bit.zy = 2 * data->bit.zx * data->bit.zy;
				data->bit.zy = burninship_abs(&data->bit.zy) + data->bit.cy;
				data->bit.zx = data->bit.zx_new + data->bit.cx;
			}
			fractal_condition(data);
		}
	}
}
