/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:38:32 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/01 01:27:30 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    fractol(t_mlx m)
{
	int 	i = 0;
	int 	j = 0;
	float	coef;
	float	complex;
	int 	num_iteration;
	float	comp_x;
	float 	comp_y;
	float 	z_im;
	float	z_re;

	coef = (float)m.Ox / SIZE_X;
	while (i < SIZE_Y)
	{
		j = 0;
		while (j < SIZE_X)
		{
			//printf("i = %d\nj = %d\n\n", i, j);
			comp_x = (float)(j) * coef - m.Ox / 2;
			comp_y = (float)i * coef - m.Oy/2;
			num_iteration = 0;
			z_im = 0;
			z_re = 0;
			float tmp;
			while (num_iteration < 255)
			{
				tmp = z_im;
				z_im = 2 * z_re * z_im + comp_y;
				z_re = z_re * z_re - tmp * tmp + comp_x;
				if (z_im * z_im + z_re * z_re > 4)
				{
					m.data[i * SIZE_X + j] = 0xFF0000;
					break;
				}
				num_iteration++;
			}
			if (num_iteration != 255)
				m.data[i * SIZE_X + j] = 0xFFFF - 0x1 * num_iteration;
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(m.ptr, m.win_ptr, m.img_ptr, 0, 0);
}
