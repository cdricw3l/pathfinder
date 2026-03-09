/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_and_perf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 19:58:58 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/09 20:02:16 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cost_and_perf.h"

void	memory_2D_cost(void)
{
	int	**matrice;
	int	*line;

	matrice = malloc(sizeof(int *));
	if (!matrice)
		return ;
	line  = malloc(sizeof(int));
	if (!line)
	{
		free(matrice);
		return ;
	}   
	printf("taille Theorique: matrice = (%lu * %d) + (%lu * %d) * %d = %lu\n",
			sizeof(int *),X, sizeof(int), Y, X,((sizeof(int *) * X) + (sizeof(int) * Y * X)));
	printf("taille Reel: matrice = (%ld * %d) +  (%ld * %d) * %d = %ld\n",
			malloc_size(matrice),X,malloc_size(line), Y, X ,(malloc_size(matrice) * X) + (malloc_size(line) * Y) * X);
	free(line);
	free(matrice);
}

void	memory_1D_cost(void)
{
	int	*matrice;

	matrice = malloc(sizeof(int));
	if (!matrice)
		return ;
	printf("taille Theorique: matrice = %lu * (%d * %d) = %lu\n", sizeof(int), X, Y, sizeof(int) * (X * Y));
	printf("taille Reel: matrice  = %lu * (%d * %d) = %lu\n", malloc_size(matrice), X, Y, malloc_size(matrice) * (X *Y));
	free(matrice);
}