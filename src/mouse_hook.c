/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarslan <zarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 18:54:53 by zarslan           #+#    #+#             */
/*   Updated: 2022/08/28 18:57:22 by zarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int mousecode, int x, int y, t_fractol *data)
{
	if (mousecode == 4)
	{
		data->bit.x_p = (-2 * data->zoom + (double)x * 4 * \
			data->zoom / WIDTH) + data->bit.x_p;
		data->bit.y_p = (-2 * data->zoom + (double)y * 4 * \
			data->zoom / HEIGHT) + data->bit.y_p;
		data->zoom *= 1.15;
		fractal_draw(data);
	}
	else if (mousecode == 5)
	{
		data->bit.x_p = (-2 * data->zoom + (double)x * 4 \
			* data->zoom / WIDTH) + data->bit.x_p;
		data->bit.y_p = (-2 * data->zoom + (double)y * 4 \
			* data->zoom / HEIGHT) + data->bit.y_p;
		data->zoom /= 1.15;
		fractal_draw(data);
	}
	return (1);
}
