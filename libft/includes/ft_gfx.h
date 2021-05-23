/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gfx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 17:23:17 by eniini            #+#    #+#             */
/*   Updated: 2021/05/22 16:04:11 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GFX_H
# define FT_GFX_H

# include <math.h>
# include "libft.h"

# define RAD_CON	0.01745329251993888928

//	Rotation matrix for RGB/integer colors
typedef struct s_rgb_mat
{
	float		rix[3][3];
	float		cos_a;
	float		sin_a;
	double		axis_unit;
}				t_rgb_mat;

/*
*	Some utility functions require precise information about the window
*	that's being drawn to. gfxinfo solves the problem while respecting
*	Norme's function parameter limit.
*/
typedef struct s_gfxinfo
{
	int			win_width;
	int			win_height;
	int			bpp;
	char		*one_d_addr;
	char		**two_d_addr;
}				t_gfxinfo;

int				ft_color_lerp(int c1, int c2, double p);

int				ft_i_lerp(int a, int b, double p);
double			ft_inverse_i_lerp(int a, int b, int x);

double			ft_d_lerp(double a, double b, double p);
double			ft_inverse_d_lerp(double a, double b, double x);

int				ft_create_bmp(char *filename, t_gfxinfo *info);

int				ft_hueshift(int c, double p);

t_gfxinfo	*ft_init_1d_info(int win_w, int win_h, int bpp, char *addr);
t_gfxinfo	*ft_init_2d_info(int win_w, int win_h, int bpp, char **addr);

double			ft_smoothstep(double start, double end, double x);

#endif
