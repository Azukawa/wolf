/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gfx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 17:23:17 by eniini            #+#    #+#             */
/*   Updated: 2021/06/02 16:04:49 by eniini           ###   ########.fr       */
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
*	Some utility functions require precise information about the window/image
*	that's being drawn to or read from.
*	gfxinfo solves the problem while also respecting
*	Norme's function parameter limit.
*/
typedef struct s_gfxinfo
{
	int				img_width;
	int				img_height;
	int				bpp;
	unsigned char	*one_d_addr;
	unsigned char	**two_d_addr;
}					t_gfxinfo;

uint32_t		ft_argb_lerp(uint32_t c1, uint32_t c2, double p);

int				ft_color_lerp(int c1, int c2, double p);

int				ft_i_lerp(int a, int b, double p);
double			ft_inverse_i_lerp(int a, int b, int x);

double			ft_d_lerp(double a, double b, double p);
double			ft_inverse_d_lerp(double a, double b, double x);

int				ft_create_bmp(char *filename, t_gfxinfo *info);

t_gfxinfo		*ft_load_bmp(const char *imagepath);

int				ft_hueshift(int c, double p);

t_gfxinfo		*ft_init_1d_info(int w, int h, int bpp, unsigned char *c);
t_gfxinfo		*ft_init_2d_info(int w, int h, int bpp, unsigned char **c);

double			ft_smoothstep(double start, double end, double x);

#endif
