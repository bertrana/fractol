/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandlebrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 03:42:55 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/02 03:54:41 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mandelbrot_draw(t_mlx m, double c[])
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
		z[IM] = 2 * z[REAL] * z[IM] + c[IM];
		z[REAL] = z[REAL] * z[REAL] - tmp * tmp + c[REAL];
	}
	return (iter);
}

void	mandelbrot(t_mlx m, double z[2])
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
			count[ITER] = mandelbrot_draw(m, c);
			m.data[count[Y] * SIZE_X + count[X]++] = color(m, count[ITER]);
		}
	}
}
