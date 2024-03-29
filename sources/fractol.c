/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:38:32 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/02 03:56:49 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		color(t_mlx m, int iter)
{
	int col;
	int tmp;

	tmp = iter;
	col = 0;
	if (iter >= m.num_iteration)
		return (0);
	else if (m.num_color == 1)
	{
		iter = iter % 6;
		(iter == 1) && (col = 0x0000FF);
		(iter == 2) && (col = 0x00FF00);
		(iter == 3) && (col = 0xFF0000);
		(iter == 4) && (col = 0x00FFFF);
		(iter == 5) && (col = 0xFF00FF);
		(iter == 0) && (col = 0xFFFF00);
	}
	else if (m.num_color == 2)
		col = 0xFF - 0x1 * tmp;
	return (col);
}

int		ship_draw(t_mlx m, double c[])
{
	int		iter;
	double	tmp;
	double	z[2];

	iter = 0;
	z[IM] = 0;
	z[REAL] = 0;
	while (iter++ < m.num_iteration &&
		z[IM] * z[IM] + z[REAL] * z[REAL] < 4)
	{
		tmp = z[IM];
		z[IM] = -2 * fabs(z[REAL] * z[IM]) + c[IM];
		z[REAL] = z[REAL] * z[REAL] - tmp * tmp + c[REAL];
	}
	return (iter);
}

void	ship(t_mlx m, double z[2])
{
	int		count[3];
	double	c[2];

	count[Y] = -1;
	while (count[Y]++ < SIZE_Y - 1)
	{
		count[X] = 0;
		while (count[X] < SIZE_X)
		{
			c[REAL] = m.min_x + (double)count[X] * m.coef_x -
					(double)m.move_x / SIZE_X;
			c[IM] = m.max_y - (double)count[Y] * m.coef_x -
					(double)m.move_y / SIZE_Y;
			count[ITER] = ship_draw(m, c);
			m.data[count[Y] * SIZE_X + count[X]++] = color(m, count[ITER]);
		}
	}
}

void	fractol(t_mlx m)
{
	double	z[2];

	z[IM] = 0;
	z[REAL] = 0;
	if (m.fract_type == 1)
		mandelbrot(m, z);
	else if (m.fract_type == 2)
		julia(m, m.k);
	else if (m.fract_type == 3)
		ship(m, z);
	mlx_put_image_to_window(m.ptr, m.win_ptr, m.img_ptr, 0, 0);
}
