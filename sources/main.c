/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:38:06 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/01 16:15:19 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		b_close(void *param)
{
	(void)param;
	exit(0);
}

//126 up
//125 down
//124 right
//123 left
//78 +
//69 -

int		key_press(int keycode, void *param)
{
	t_mlx	*m;

	m = (t_mlx *)param;
	if (keycode == 53)
		exit(0);
	if (keycode == 78)
	{
		m->Ox *= 0.95;
		m->Oy *= 0.95;
		m->num_iteration += 2;
	}
	if (keycode == 69)
	{
		m->Ox *= 1.1;
		m->Oy *= 1.1;
		m->num_iteration -= 2;
	}
	m->coef = m->Ox / SIZE_X;
	fractol(*m);
	return (0);
}

void	ex_error(int num)
{
	char	*write_err;

	write_err = NULL;
	if (num == 1)
		write_err = "Mandelbrot\nJulia\n";

	write(2, write_err, ft_strlen(write_err) + 1);
	exit(EXIT_FAILURE);
}

void	ft_init(t_mlx *mlx, char *argc)
{
	if (ft_strcmp(argc, "Mandelbrot") == 0)
		mlx->fract_type = MANDELBROT;
	else if (ft_strcmp(argc, "Julia") == 0)
		mlx->fract_type = JULIA;
	else
		ex_error(1);
    mlx->ptr = mlx_init();
    mlx->win_ptr = mlx_new_window(mlx->ptr, SIZE_X, SIZE_Y, "Fractol");
	mlx->img_ptr = mlx_new_image(mlx->ptr, SIZE_X, SIZE_Y);
	mlx->data = (int *)mlx_get_data_addr(mlx->img_ptr, &(mlx->bpp),
			&(mlx->size_l), &(mlx->e));
	mlx->Ox = 4;
	mlx->Oy = 4;
	mlx->zoom = 0;
	mlx->coef = mlx->Ox / SIZE_X;
	mlx->num_iteration = 255;
}

int     main(int argv, char **argc)
{
	t_mlx	m;

	if (argv != 2)
		ex_error(1);
	ft_init(&m, argc[1]);
	fractol(m);
	mlx_hook(m.win_ptr, 17, 0, b_close, &m);
	mlx_hook(m.win_ptr, 2, 0, key_press, &m);
	mlx_loop(&m);
    return (0);
}