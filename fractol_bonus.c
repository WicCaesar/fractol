/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 07:58:06 by cnascime          #+#    #+#             */
/*   Updated: 2023/03/20 13:22:19 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	guide(void);
void	load(t_setup *ol);
int		eject(t_setup *ol);

int	main(int argc, char **argv)
{
	t_setup	ol;
	char	*type;

	type = argv[argc - 1];
	if (argc == 2 || ft_strcmp(type, "mandelbrot") == 0
		|| ft_strcmp(type, "julia1") == 0 || ft_strcmp(type, "julia2") == 0
		|| ft_strcmp(type, "julia3") == 0 || ft_strcmp(type, "julia4") == 0
		|| ft_strcmp(type, "julia5") == 0 || ft_strcmp(type, "tricorn") == 0
		|| ft_strcmp(type, "burningship") == 0)
	{
		ft_strtolower(type);
		ol.type = type;
		load(&ol);
		render(&ol);
		mlx_hook(ol.window, 17, 0, eject, &ol);
		mlx_key_hook(ol.window, &keypress, &ol);
		mlx_mouse_hook(ol.window, &buttonpress, &ol);
		mlx_loop(ol.mlx);
	}
	else
		guide();
	return (0);
}
// Since I am using a method to reset the fractal by pressing the middle button,
// I had to implement more verifications other than argc == 2, because my reset
// function passes argc = 1 and the type of the fractal only.

// Initialises the connector and some variables of the struct.
void	load(t_setup *ol)
{
	ol->mlx = mlx_init();
	if (!ol->mlx)
		eject(ol);
	ol->window = mlx_new_window(ol->mlx, WINDOWWIDTH, WINDOWHEIGHT, "fract'ol");
	if (!ol->window)
	{
		free(ol->window);
		eject(ol);
	}
	ol->image = mlx_new_image(ol->mlx, WINDOWWIDTH, WINDOWHEIGHT);
	ol->address = mlx_get_data_addr(ol->image, &ol->bitsperpixel,
			&ol->linelength, &ol->endian);
	ol->minreal = -2.0;
	ol->maxreal = 2.0;
	ol->medreal = (ol->maxreal - ol->minreal);
	ol->minimag = -2.0;
	ol->maximag = 2.0;
	ol->palette = 0;
	palette(ol);
}

// Calls for the specific fractal function according to the user's parameters.
double	fractal(t_setup *ol)
{
	double	creal;
	double	cimag;

	creal = ol->minreal + ol->x * (ol->maxreal - ol->minreal) / WINDOWWIDTH;
	cimag = ol->maximag + ol->y * (ol->minimag - ol->maximag) / WINDOWHEIGHT;
	if (ft_strcmp(ol->type, "mandelbrot") == 0)
		return (mandelbrot(ol, creal, cimag));
	else if (ft_strcmp(ol->type, "julia1") == 0)
		return (julia1(ol, creal, cimag));
	else if (ft_strcmp(ol->type, "julia2") == 0)
		return (julia2(ol, creal, cimag));
	else if (ft_strcmp(ol->type, "julia3") == 0)
		return (julia3(ol, creal, cimag));
	else if (ft_strcmp(ol->type, "julia4") == 0)
		return (julia4(ol, creal, cimag));
	else if (ft_strcmp(ol->type, "julia5") == 0)
		return (julia5(ol, creal, cimag));
	else if (ft_strcmp(ol->type, "tricorn") == 0)
		return (tricorn(ol, creal, cimag));
	else if (ft_strcmp(ol->type, "burningship") == 0)
		return (burningship(ol, creal, cimag));
	else
		guide();
	return (0);
}
