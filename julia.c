/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:49:06 by cnascime          #+#    #+#             */
/*   Updated: 2023/03/20 11:11:01 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* The Julia set is named after the French mathematician Gaston Julia who 
investigated their properties circa 1915 and culminated in his paper in 1918.
The Julia set consists of values such that an arbitrarily small perturbation can
cause drastic changes in the sequence of iterated function values, as opposed to
the Fatou set, which consists of values with the property that all nearby values
behave similarly under repeated iteration of the function. Thus the behaviour of 
the function on the Julia set is "chaotic", while the Fatou set has a "regular" 
behaviour (Julia "laces" and Fatou "dusts").
*/

// Sparkles
double	julia1(t_setup *ol, double zreal, double zimag)
{
	double	tempimag;

	ol->iteration = 0.0;
	ol->creal = -0.63;
	ol->cimag = 0.43;
	while (ol->iteration < MAXITERATIONS
		&& ((zreal * zreal) + (zimag * zimag)) < 4)
	{
		tempimag = 2.0 * zreal * zimag + ol->cimag;
		zreal = (zreal * zreal) - (zimag * zimag) + ol->creal;
		zimag = tempimag;
		ol->iteration++;
	}
	if (ol->iteration == MAXITERATIONS)
		return (MAXITERATIONS);
	return (ol->iteration);
}

// Spirals
double	julia2(t_setup *ol, double zreal, double zimag)
{
	double	tempimag;

	ol->iteration = 0.0;
	ol->creal = -0.76;
	ol->cimag = 0.05;
	while (ol->iteration < MAXITERATIONS
		&& ((zreal * zreal) + (zimag * zimag)) < 4)
	{
		tempimag = 2.0 * zreal * zimag + ol->cimag;
		zreal = (zreal * zreal) - (zimag * zimag) + ol->creal;
		zimag = tempimag;
		ol->iteration++;
	}
	if (ol->iteration == MAXITERATIONS)
		return (MAXITERATIONS);
	return (ol->iteration);
}

// Hamburger
double	julia3(t_setup *ol, double zreal, double zimag)
{
	double	tempimag;

	ol->iteration = 0.0;
	ol->creal = -1.1;
	ol->cimag = 0.0;
	while (ol->iteration < MAXITERATIONS
		&& ((zreal * zreal) + (zimag * zimag)) < 4)
	{
		tempimag = 2.0 * zreal * zimag + ol->cimag;
		zreal = (zreal * zreal) - (zimag * zimag) + ol->creal;
		zimag = tempimag;
		ol->iteration++;
	}
	if (ol->iteration == MAXITERATIONS)
		return (MAXITERATIONS);
	return (ol->iteration * 42 * 83);
}

// Snowflakes
double	julia4(t_setup *ol, double zreal, double zimag)
{
	double	tempimag;

	ol->iteration = 0.0;
	ol->creal = 0.29;
	ol->cimag = 0.03;
	while (ol->iteration < MAXITERATIONS
		&& ((zreal * zreal) + (zimag * zimag)) < 4)
	{
		tempimag = 2.0 * zreal * zimag + ol->cimag;
		zreal = (zreal * zreal) - (zimag * zimag) + ol->creal;
		zimag = tempimag;
		ol->iteration++;
	}
	if (ol->iteration == MAXITERATIONS)
		return (MAXITERATIONS);
	return (ol->iteration);
}

// Circle
double	julia5(t_setup *ol, double zreal, double zimag)
{
	double	tempimag;

	ol->iteration = 0.0;
	ol->creal = -0.0;
	ol->cimag = 0.0;
	while (ol->iteration < MAXITERATIONS
		&& ((zreal * zreal) + (zimag * zimag)) < 4)
	{
		tempimag = 2.0 * zreal * zimag + ol->cimag;
		zreal = (zreal * zreal) - (zimag * zimag) + ol->creal;
		zimag = tempimag;
		ol->iteration++;
	}
	if (ol->iteration == MAXITERATIONS)
		return (MAXITERATIONS);
	return (ol->iteration);
}
