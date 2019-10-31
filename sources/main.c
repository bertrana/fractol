/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:38:06 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/01 00:14:39 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		b_close(void *param)
{
	(void)param;
	exit(0);
}

int		key_press(int keycode, void *param)
{
	(void)param;
	if (keycode == 53)
		exit(0);
	return (0);
}

void	ft_init(t_mlx *mlx)
{
    mlx->ptr = mlx_init();
    mlx->win_ptr = mlx_new_window(mlx->ptr, SIZE_X, SIZE_Y, "Fractol");
	mlx->img_ptr = mlx_new_image(mlx->ptr, SIZE_X, SIZE_Y);
	mlx->data = (int *)mlx_get_data_addr(mlx->img_ptr, &(mlx->bpp),
			&(mlx->size_l), &(mlx->e));
	mlx->Ox = 4;
	mlx->Oy = 4;
}

int     main()
{
	t_mlx	m;

	ft_init(&m);
	fractol(m);
	mlx_hook(m.win_ptr, 17, 0, b_close, &m);
	mlx_hook(m.win_ptr, 2, 0, key_press, &m);
	mlx_loop(&m);
    return (0);
}