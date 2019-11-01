/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 05:32:11 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/01 11:05:14 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdio.h>
# include <stdlib.h>
# include "mlx.h"
# include "libft.h"
# include <math.h>
//#include <zconf.h>

# define SIZE_X 800
# define SIZE_Y 800

# define MANDELBROT 1
# define JULIA 2

#define IM 0
#define REAL 1

#define X 0
#define Y 1
#define ITER 2


typedef struct	s_mlx
{
    void		*ptr;
    void		*win_ptr;
    void		*img_ptr;
    int			*data;
    int			bpp;
    int			size_l;
    int			e;

    int 		fract_type;
    float		coef;
	int 		num_iteration;

    int 		Ox;
    int 		Oy;

	float		k[2];
}				t_mlx;

void	fractol(t_mlx m);
int 	julia_k(int x, int y, t_mlx *m);

#endif
