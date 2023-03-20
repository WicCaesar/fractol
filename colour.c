/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 07:34:46 by cnascime          #+#    #+#             */
/*   Updated: 2023/03/20 13:01:49 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

// Paints the background.
void	paintbucket(t_setup *ol)
{
	ol->r = 197;
	ol->g = 56;
	ol->b = 249;
	render(ol);
}
