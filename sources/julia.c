/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 03:44:15 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/02 03:52:41 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		julia_draw(t_mlx m, double c[], double k[])
{
	int		iter;
	double	tmp;
	double	z[2];

	iter = 0;
	z[IM] = c[IM];
	z[REAL] = c[REAL];
	c[REAL] = k[REAL];
	c[IM] = k[IM];
	while (iter++ < m.num_iteration &&
			z[IM] * z[IM] + z[REAL] * z[REAL] < 4)
	{
		tmp = z[IM];
		z[IM] = 2 * z[REAL] * z[IM] + c[IM];
		z[REAL] = z[REAL] * z[REAL] - tmp * tmp + c[REAL];
	}
	return (iter);
}

void	julia(t_mlx m, double k[2])
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
			count[ITER] = julia_draw(m, c, k);
			m.data[count[Y] * SIZE_X + count[X]++] = color(m, count[ITER]);
		}
	}
	mlx_put_image_to_window(m.ptr, m.win_ptr, m.img_ptr, 0, 0);
}

int		julia_k(int x, int y, t_mlx *m)
{
	if (m->fract_type != 2)
		return (0);
	m->k[REAL] = (double)(x + m->coef_x) / SIZE_X;
	m->k[IM] = (double)(y + m->coef_x) / SIZE_Y;
	julia(*m, m->k);
	return (0);
}
