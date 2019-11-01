/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:38:32 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/01 16:17:58 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		color(t_mlx m, int iter)
{
	if (m.num_iteration > iter)
		return (0xFFFF - 0x1 * iter);
	else
		return (0);
}

int		mandelbrot_draw(t_mlx m, double c[])
{
	int 	iter;
	double	tmp;
	double 	z[2];

	iter = 0;
	z[IM] = 0;
	z[REAL] = 0;
	while (iter++ < m.num_iteration &&
		   z[IM] * z[IM] + z[REAL] * z[REAL] < 4)
	{
		tmp = z[IM];
		z[IM] = 2 * z[REAL] * z[IM] + c[IM];
		z[REAL] = z[REAL] * z[REAL] - tmp * tmp + c[REAL];
	}
	return (iter);
}

void    mandelbrot(t_mlx m, double z[2])
{
	int 	count[3];
	double	c[2];

	count[Y] = -1;
	while (count[Y]++ < SIZE_Y - 1)
	{
		count[X] = 0;
		while (count[X] < SIZE_X)
		{
			c[REAL] = (double)count[X] * m.coef - (double)m.Ox / 2;
			c[IM] = (double)count[Y] * m.coef - (double)m.Oy / 2;
			count[ITER] = mandelbrot_draw(m, c);
			m.data[count[Y] * SIZE_X + count[X]++] = color(m, count[ITER]);
		}
	}
}

int		julia_draw(t_mlx m, double c[])
{
	int 	iter;
	double	tmp;
	double 	z[2];

	iter = 0;
	z[IM] = c[IM];
	z[REAL] = c[REAL];
	c[REAL] = m.k[REAL];
	c[IM] = m.k[IM];
	while (iter++ < m.num_iteration &&
		   z[IM] * z[IM] + z[REAL] * z[REAL] < 4)
	{
		tmp = z[IM];
		z[IM] = 2 * z[REAL] * z[IM] + c[IM];
		z[REAL] = z[REAL] * z[REAL] - tmp * tmp + c[REAL];
	}
	return (iter);
}

void	julia(t_mlx m, double z[2])
{
	int 	count[3];
	double	c[2];

	count[Y] = -1;
	while (count[Y]++ < SIZE_Y - 1)
	{
		count[X] = 0;
		while (count[X] < SIZE_X)
		{
			c[REAL] = (double)count[X] * m.coef - (double)m.Ox / 2;
			c[IM] = (double)count[Y] * m.coef - (double)m.Oy / 2;
			count[ITER] = julia_draw(m, c);
			m.data[count[Y] * SIZE_X + count[X]++] = color(m, count[ITER]);
		}
	}
	mlx_put_image_to_window(m.ptr, m.win_ptr, m.img_ptr, 0, 0);
}

int 	julia_k(int x, int y, t_mlx *m)
{
	double	z[2];

	m->k[REAL] = (double)(x + m->coef) / SIZE_X;
	m->k[IM] = (double)(y + m->coef)/ SIZE_Y;
	julia(*m, z);
	return (0);
}

void	fractol(t_mlx m)
{
	double	z[2];

	z[IM] = 0;
	z[REAL] = 0;
	if (m.fract_type == 1)
		mandelbrot(m, z);
	else if (m.fract_type == 2)
	{
		mlx_hook(m.win_ptr, 6, 0, julia_k, &m);
	}
	mlx_put_image_to_window(m.ptr, m.win_ptr, m.img_ptr, 0, 0);
}
