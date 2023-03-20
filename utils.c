/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 03:09:31 by cnascime          #+#    #+#             */
/*   Updated: 2023/03/20 13:06:01 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv);

// Displays a message informing the user how to use the program.
void	guide(void)
{
	ft_putstr_fd(2, "Digite o nome exato do fractal que deseja criar.\n");
	ft_putstr_fd(2, "Por exemplo: ./fractol mandelbrot OU ./fractol julia3\n");
	exit(1);
}

int	keypress(int pressed, t_setup *ol)
{
	if (pressed == ESC)
		eject(ol);
	return (0);
}

int	buttonpress(int pressed, int x, int y, t_setup *ol)
{
	(void)x;
	(void)y;
	if (pressed == SCROLLUP)
	{
		ol->minreal *= 0.9;
		ol->maxreal *= 0.9;
		ol->minimag *= 0.9;
		ol->maximag *= 0.9;
	}
	else if (pressed == SCROLLDOWN)
	{
		ol->minreal *= 1.1;
		ol->maxreal *= 1.1;
		ol->minimag *= 1.1;
		ol->maximag *= 1.1;
	}
	render(ol);
	return (0);
}
// ? Is there any way (in the minilibx) to keep changing colours (multiplying)
// ? WHILE the right button is pressed?

// Destroys the image, the window and frees the connector.
int	eject(t_setup *ol)
{
	if (ol->image)
		mlx_destroy_image(ol->mlx, ol->image);
	if (ol->window)
		mlx_destroy_window(ol->mlx, ol->window);
	free(ol->mlx);
	exit(1);
}
