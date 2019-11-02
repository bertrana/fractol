/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 03:48:52 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/02 04:03:10 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_press2(int keycode, t_mlx *m)
{
	if (keycode == 78)
	{
		m->min_x *= 0.95;
		m->max_y *= 0.95;
		m->max_x *= 0.95;
		m->num_iteration += 2;
	}
	if (keycode == 69 && m->num_iteration > 2)
	{
		m->min_x *= 1.1;
		m->max_y *= 1.1;
		m->max_x *= 1.1;
		m->num_iteration -= 2;
	}
}

int		key_press(int keycode, void *param)
{
	t_mlx	*m;

	m = (t_mlx *)param;
	if (keycode == 53)
		exit(0);
	(keycode == 18) && (m->fract_type = 1);
	(keycode == 19) && (m->fract_type = 2);
	(keycode == 20) && (m->fract_type = 3);
	(keycode == 12) && (m->num_color = 1);
	(keycode == 13) && (m->num_color = 2);
	(keycode == 46) && (m->num_iteration += 2);
	if (keycode == 37 && m->num_iteration > 2)
		m->num_iteration -= 2;
	key_press2(keycode, m);
	m->coef_x = (m->max_x - m->min_x) / (SIZE_X - 1);
	fractol(*m);
	return (0);
}
