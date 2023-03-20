/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 08:01:01 by cnascime          #+#    #+#             */
/*   Updated: 2023/03/20 13:07:30 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include <math.h>

# define WINDOWNAME "fract'ol"
# define WINDOWWIDTH (700)
# define WINDOWHEIGHT (700)
# define MAXITERATIONS (255)

# define LEFTBUTTON (1)
# define MIDDLEBUTTON (2)
# define RIGHTBUTTON (3)
# define SCROLLUP (4)
# define SCROLLDOWN (5)

# if __APPLE__
#  include "libmlx/mlx.h"
#  define CLOSE (17)
#  define ESC (53)
# elif __unix__
#  include "libmlx_Linux/mlx.h"
#  define CLOSE (33)
#  define ESC (65307)
# endif

typedef struct s_setup
{
	void	*mlx;
	void	*window;
	void	*image;
	char	*address;
	char	*type;
	double	x;
	double	y;
	double	zreal;
	double	zimag;
	double	creal;
	double	cimag;
	double	minreal;
	double	maxreal;
	double	minimag;
	double	maximag;
	double	iteration;
	double	r;
	double	g;
	double	b;
	int		bitsperpixel;
	int		linelength;
	int		endian;
}	t_setup;

void	guide(void);
void	load(t_setup *ol);
double	fractal(t_setup *ol);
double	mandelbrot(t_setup *ol, double creal, double cimag);
double	julia1(t_setup *ol, double zreal, double zimag);
double	julia2(t_setup *ol, double zreal, double zimag);
double	julia3(t_setup *ol, double zreal, double zimag);
double	julia4(t_setup *ol, double zreal, double zimag);
double	julia5(t_setup *ol, double zreal, double zimag);
void	ft_pixelput(t_setup *ol, int x, int y, int colour);
int		trgb(int t, int r, int g, int b);
void	paintbucket(t_setup *ol);
void	render(t_setup *ol);
int		keypress(int pressed, t_setup *ol);
int		buttonpress(int pressed, int x, int y, t_setup *ol);
int		eject(t_setup *ol);
#endif
