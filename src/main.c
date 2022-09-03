/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarslan <zarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:04:04 by zarslan           #+#    #+#             */
/*   Updated: 2022/09/02 10:38:05 by zarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fractal_type(char *argv, t_fractol *data)
{
	if (!ft_strncmp(argv, "julia", 6))
	{	
		data->fractal = 1;
	}
	else if (!ft_strncmp(argv, "mandelbrot", 11))
	{
		data->fractal = 2;
	}
	else if (!ft_strncmp(argv, "burningship", 13))
	{
		data->fractal = 3;
	}
	else
		return (0);
	return (1);
}

void	fractal_draw(t_fractol *data)
{
	if (data->fractal == 1)
		julia(data);
	if (data->fractal == 2)
		mandelbrot(data);
	if (data->fractal == 3)
		burningship(data);
	mlx_put_image_to_window(&data->mlx, data->win, data->img.img, 0, 0);
}

void	fractal_init(t_fractol *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fract'ol");
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp, \
		&data->img.line_length, &data->img.endian);
	fractal_reset(data);
	data->color = 190701;
}

int	main(int argc, char **argv)
{
	t_fractol	data;

	if (argc == 2)
	{
		if (!fractal_type(argv[1], &data))
		{
			write(1, "Fractal adını eksik veya hatalı girdiniz.\n", 46);
			write(1, "Fractal adları:  \n", 20);
			write (1, "'julia'\n'mandelbrot'\n'burnship\n", 32);
			exit(0);
		}
		fractal_init(&data);
		fractal_draw(&data);
		mlx_hook(data.win, 17, 0, close_hook, &data);
		mlx_key_hook(data.win, key_hook, &data);
		mlx_mouse_hook(data.win, mouse_hook, &data);
		mlx_loop(data.mlx);
	}
	else
	{
		write(1, "Eksik veya fazla argüman girdiniz.\n", 37);
		write(1, "Fractal adları:  \n", 20);
		write (1, "'julia'\n'mandelbrot'\n'burnship\n", 32);
		exit(1);
	}
}
