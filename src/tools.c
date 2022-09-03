/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarslan <zarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:27:50 by zarslan           #+#    #+#             */
/*   Updated: 2022/08/29 23:19:02 by zarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_reset(t_fractol *data)
{
	data->zoom = 1;
	data->bit.x_p = 0;
	data->bit.y_p = 0;
	data->bit.gez_x = 0;
	data->bit.gez_y = 0;
	data->bit.cx = -0.8;
	data->bit.cy = 0.156;
}

double	burninship_abs(double *zy)
{
	if (*zy < 0)
		*zy = *zy * -1;
	return (*zy);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 && *s2 && *s1 == *s2 && n > 1)
	{
		s1++;
		s2++;
		n--;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
