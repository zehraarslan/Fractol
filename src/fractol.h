/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarslan <zarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:03:58 by zarslan           #+#    #+#             */
/*   Updated: 2022/09/02 10:52:20 by zarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH				800
# define HEIGHT				800

# include	<stdio.h>
# include	<stdlib.h>
# include <unistd.h>
# include "../miniLibx/mlx.h"

typedef struct s_bit {
	double	x;
	double	y;
	double	zx;
	double	zy;
	double	zx_new;
	double	cx;
	double	cy;
	int		iter;
	double	x_p;
	double	y_p;
	double	gez_x;
	double	gez_y;
}	t_bit;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_fractol {
	void	*mlx;
	void	*win;
	t_img	img;
	t_bit	bit;
	double	zoom;
	int		fractal;
	double	color;
}	t_fractol;

void	fractal_init(t_fractol *data);
int		fractal_type(char *argv, t_fractol *data);
void	fractal_draw(t_fractol *data);
void	julia(t_fractol *data);
void	mandelbrot(t_fractol *data);
void	burningship(t_fractol *data);
double	burninship_abs(double *zy);
void	fractal_reset(t_fractol *data);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		close_hook(t_fractol *data);
int		key_hook(int keycode, t_fractol *data);
int		key_hook2(int keycode, t_fractol *data);
int		key_hook_color(int keycode, t_fractol *data);
int		key_hook_color2(int keycode, t_fractol *data);
int		key_hook_julia(int keycode, t_fractol *data);
int		key_hook_julia2(int keycode, t_fractol *data);
int		mouse_hook(int mousecode, int x, int y, t_fractol *data);
#endif