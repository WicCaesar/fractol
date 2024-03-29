/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:01:47 by cnascime          #+#    #+#             */
/*   Updated: 2023/03/20 13:22:16 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

/* The Mandelbrot set formula is
z = z² + c		=>		z = (zreal * zreal) + (zimag * zimag) + complex constant
where	c = (x + y) * i		point of interest = (real + imaginary) * iterations.
For Mandelbrot, the parameter is the xy coordinates of the pixel, 
starting at -2, 2.
Values between 0 and 1 are within the set.
0 and 1 are fixed points. 0 is an attractive point, 1 is a repelling point.
After the first iteration, negative numbers become positive.
Values from -1 to 1 remain localised (within the set), and are traditionally
coloured black.
All other orbits (< -1 or > 1) shoot off towards infinity (outside the set),
so they are coloured based on how quickly they escaped.

Examples:
If c = 1, it heads towards infinity, so it's not part of the Mandelbrot set.
If c = 0.1, it loops in 0.11, so it is part of the Mandelbrot set.
If c = -1, it loops between -1 and 0, so it is part of the Mandelbrot set.
If c = -1.9, it gets a dynamic behaviour, but never leaves the local area.
Anytime the value of the orbit goes beyond an absolute two, it is guaranteed
to hit towards infinity.
All the positive values from 0 to 0.25 are part of the Mandelbrot set.
All the values < -2 are outside the Mandelbrot set.
*/

// Attributes a colour to every pixel of the window based on the number of
// iterations (up to the predefined max). Returns the number of iterations.
// By rendering with ft_pixelput (custom version of the original mlx_pixel_put),
// it is necessary to push the image to the window by the end of the process.
// With native mlx_pixel_put, it's not necessary (pixels are placed one by one).
// For the colouring process, it admits both decimal and hexadecimal values. 0x
void	render(t_setup *ol)
{
	ol->iteration = 0.0;
	ol->x = 0.0;
	ol->y = 0.0;
	while (ol->y != WINDOWHEIGHT)
	{
		ol->x = 0.0;
		while (ol->x != WINDOWWIDTH)
		{
			ol->iteration = fractal(ol);
			splatter(ol);
			ol->x++;
		}
		ol->y++;
	}
	mlx_put_image_to_window(ol->mlx, ol->window, ol->image, 0, 0);
}
// For more interesting colours, multiply iteration by 42 * 83.

// Returns the number of iterations it takes that point to escape the set.
double	mandelbrot(t_setup *ol, double creal, double cimag)
{
	double	tempimag;

	ol->iteration = 0.0;
	ol->zreal = 0.0;
	ol->zimag = 0.0;
	while (ol->iteration < MAXITERATIONS
		&& ((ol->zreal * ol->zreal) + (ol->zimag * ol->zimag)) <= 4)
	{
		tempimag = 2.0 * ol->zreal * ol->zimag + cimag;
		ol->zreal = (ol->zreal * ol->zreal) - (ol->zimag * ol->zimag) + creal;
		ol->zimag = tempimag;
		ol->iteration++;
	}
	if (ol->iteration == MAXITERATIONS)
		return (MAXITERATIONS);
	ol->iteration = ol->iteration + 0.9
		- log(log2(fabs(ol->zimag * ol->zimag + ol->zreal * ol->zreal)));
	return (ol->iteration);
}

/* The tricorn, or Mandelbar set, maps with z = z^-2 + c instead of z = z^2 + c
like the Mandelbrot set. In addition to smaller tricorns, smaller versions of
the Mandelbrot set are also contained within the tricorn fractal. */

double	tricorn(t_setup *ol, double creal, double cimag)
{
	double	tempimag;

	ol->iteration = 0.0;
	ol->zreal = 0.0;
	ol->zimag = 0.0;
	while (ol->iteration < MAXITERATIONS
		&& ((ol->zreal * ol->zreal) + (ol->zimag * ol->zimag)) <= 4)
	{
		tempimag = -2.0 * ol->zreal * ol->zimag + cimag;
		ol->zreal = (ol->zreal * ol->zreal) - (ol->zimag * ol->zimag) + creal;
		ol->zimag = tempimag;
		ol->iteration++;
	}
	if (ol->iteration == MAXITERATIONS)
		return (MAXITERATIONS);
	return (ol->iteration);
}

/* The Burning Ship fractal, first described and created by Michael Michelitsch 
and Otto Eberhard Rössler in 1992, is generated by iterating the function in the
complex plane, which will either escape or remain bounded. The difference 
between this calculation and that for the Mandelbrot set is that the real and 
imaginary components are set to their respective absolute values before squaring
at each iteration. */

double	burningship(t_setup *ol, double creal, double cimag)
{
	double	tempimag;

	ol->iteration = 0.0;
	ol->zreal = 0.0;
	ol->zimag = 0.0;
	while (ol->iteration < MAXITERATIONS
		&& ((ol->zreal * ol->zreal) + (ol->zimag * ol->zimag)) <= 4)
	{
		tempimag = fabs(2.0 * ol->zreal * ol->zimag) + -cimag;
		ol->zreal = (ol->zreal * ol->zreal) - (ol->zimag * ol->zimag) + creal;
		ol->zimag = tempimag;
		ol->iteration++;
	}
	if (ol->iteration == MAXITERATIONS)
		return (MAXITERATIONS);
	return (ol->iteration);
}
