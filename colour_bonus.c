/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 07:34:46 by cnascime          #+#    #+#             */
/*   Updated: 2023/03/20 16:48:50 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

// Faster than mlx_pixel_put (doesn't check if the pixel is inside the window).
void	ft_pixelput(t_setup *ol, int x, int y, int colour)
{
	char	*pixel;

	pixel = ol->address + (y * ol->linelength + x * (ol->bitsperpixel / 8));
	*(unsigned int *)pixel = colour;
}

// Converts the colour components to a single integer.
int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

// Actually paints the background.
void	paintbucket(t_setup *ol, double r, double g, double b)
{
	ol->r = r;
	ol->g = g;
	ol->b = b;
}

// Passes the colour values for the paintbucket.
// 0 = Smooth Matrix	1 = Hard candy		2 = Voltaic tears
// 3 = Firefly			4 = Toxic bee		5 = Beto Jamaica
// 6 = Ketchup Mustard	7 = Frosti
void	palette(t_setup *ol)
{
	if (ol->palette == 0)
		paintbucket(ol, 0, 255, 0);
	else if (ol->palette == 1)
		paintbucket(ol, 197, 56, 249);
	else if (ol->palette == 2)
		paintbucket(ol, 248, 1, 96);
	else if (ol->palette == 3)
		paintbucket(ol, 14, 24, 105);
	else if (ol->palette == 4)
		paintbucket(ol, 0, 0, 0);
	else if (ol->palette == 5)
		paintbucket(ol, 4, 2, 69);
	else if (ol->palette == 6)
		paintbucket(ol, 237, 28, 36);
	else if (ol->palette == 7)
		paintbucket(ol, 14, 26, 110 * 42 * 83);
	else if (ol->palette == 8)
	{
		paintbucket(ol, 0, 255, 0);
		ol->palette = 0;
	}
	ol->palette++;
	render(ol);
}

// By splatter I mean the shape that is formed when the number of iterations is
// within a given set.
void	splatter(t_setup *ol)
{
	if (ol->iteration == MAXITERATIONS)
	{
		if (ol->palette == 1)
			ft_pixelput(ol, ol->x, ol->y, 0x00000000);
		else if (ol->palette == 2)
			ft_pixelput(ol, ol->x, ol->y, 0x00C500F9);
		else if (ol->palette == 3)
			ft_pixelput(ol, ol->x, ol->y, 0x00714EC4);
		else if (ol->palette == 4)
			ft_pixelput(ol, ol->x, ol->y, 0x000EFC69);
		else if (ol->palette == 5)
			ft_pixelput(ol, ol->x, ol->y, 0x00FFFF00);
		else if (ol->palette == 6)
			ft_pixelput(ol, ol->x, ol->y, 0x0004E545);
		else if (ol->palette == 7)
			ft_pixelput(ol, ol->x, ol->y, 0x00FFF200);
		else if (ol->palette == 8)
			ft_pixelput(ol, ol->x, ol->y, 0x00BCE5EC);
		else
			ft_pixelput(ol, ol->x, ol->y, 0x00000000);
	}
	else
		ft_pixelput(ol, ol->x, ol->y,
			trgb(0, ol->r, ol->g * ol->iteration, ol->b));
}
