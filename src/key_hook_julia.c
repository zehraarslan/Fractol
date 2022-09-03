/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_julia.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarslan <zarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 18:55:40 by zarslan           #+#    #+#             */
/*   Updated: 2022/08/28 19:05:16 by zarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook_julia2(int keycode, t_fractol *data)
{
	if (keycode == 9)
	{
		data->bit.cx = -0.70176;
		data->bit.cy = -0.3842;
	}
	else if (keycode == 11)
	{
		data->bit.cx = 0;
		data->bit.cy = -0.8;
	}
	return (1);
}

int	key_hook_julia(int keycode, t_fractol *data)
{
	if (keycode == 6)
	{
		data->bit.cx = -0.8;
		data->bit.cy = 0.156;
	}
	else if (keycode == 7)
	{
		data->bit.cx = -0.4;
		data->bit.cy = 0.6;
	}
	else if (keycode == 8)
	{
		data->bit.cx = -0.285;
		data->bit.cy = 0.01;
	}
	else
		key_hook_julia2(keycode, data);
	return (1);
}
