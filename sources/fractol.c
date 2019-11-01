/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:38:32 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/01 12:41:25 by yjohns           ###   ########.fr       */
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

int		mandelbrot_draw(t_mlx m, float c[])
{
	int 	iter;
	float	tmp;
	float 	z[2];

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

void    mandelbrot(t_mlx m, float z[2])
{
	int 	count[3];
	float	c[2];

	count[Y] = -1;
	while (count[Y]++ < SIZE_Y - 1)
	{
		count[X] = 0;
		while (count[X] < SIZE_X)
		{
			c[REAL] = (float)count[X] * m.coef - (float)m.Ox / 2;
			c[IM] = (float)count[Y] * m.coef - (float)m.Oy / 2;
			count[ITER] = mandelbrot_draw(m, c);
			m.data[count[Y] * SIZE_X + count[X]++] = color(m, count[ITER]);
		}
	}
}

int		julia_draw(t_mlx m, float c[])
{
	int 	iter;
	float	tmp;
	float 	z[2];

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

void	julia(t_mlx m, float z[2])
{
	int 	count[3];
	float	c[2];

	count[Y] = -1;
	while (count[Y]++ < SIZE_Y - 1)
	{
		count[X] = 0;
		while (count[X] < SIZE_X)
		{
			c[REAL] = (float)count[X] * m.coef - (float)m.Ox / 2;
			c[IM] = (float)count[Y] * m.coef - (float)m.Oy / 2;
			count[ITER] = julia_draw(m, c);
			m.data[count[Y] * SIZE_X + count[X]++] = color(m, count[ITER]);
		}
	}
	mlx_put_image_to_window(m.ptr, m.win_ptr, m.img_ptr, 0, 0);
}

int 	julia_k(int x, int y, t_mlx *m)
{
	float	z[2];

	m->k[REAL] = (float)(x + m->coef) / SIZE_X;
	m->k[IM] = (float)(y + m->coef)/ SIZE_Y;
	julia(*m, z);
	return (0);
}

void	fractol(t_mlx m)
{
	float	z[2];

	z[IM] = 0;
	z[REAL] = 0;
	if (m.fract_type == 1)
		mandelbrot(m, z);
	else if (m.fract_type == 2)
	{
		julia(m, z);
	}
	mlx_put_image_to_window(m.ptr, m.win_ptr, m.img_ptr, 0, 0);
}
