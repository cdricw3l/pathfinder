/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_and_perf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 19:58:58 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/09 22:02:22 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cost_and_perf.h"

int *get_matrice(int x_max, int y_max)
{
    int *mat;
    int i;

    mat = malloc(sizeof(int) * (x_max * y_max));
    if (!mat)
        return (NULL);
    i = 0;
    while (i < (x_max * y_max))
    {
        mat[i] = i;
        i++;
    }
    return (mat);
}

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
	printf("\nTaille Theorique: matrice = (%lu * %d) + (%lu * %d) * %d = " "\033[33m%lu\033[0m\n" ,
			sizeof(int *),X, sizeof(int), Y, X,((sizeof(int *) * X) + (sizeof(int) * Y * X)));
	printf("Taille Reel: matrice = (%ld * %d) +  (%ld * %d) * %d =\t " "\033[32m%lu\033[0m\n",
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
	printf("\nTaille Theorique: matrice = %lu * (%d * %d) =\t " "\033[33m%lu\033[0m\n", sizeof(int), X, Y, sizeof(int) * (X * Y));
	printf("Taille Reel: matrice  = %lu * (%d * %d) =\t ""\033[32m%lu\033[0m\n", malloc_size(matrice), X, Y, malloc_size(matrice) * (X *Y));
	free(matrice);
}

time_t	perf_1D_cost(void)
{
	time_t start;
    time_t end;
	size_t	i;
	size_t	sum;
	int *matrice;

	matrice = get_matrice(X,Y);
	if (!matrice)
		return (0);
	i = 0;
	sum = 0;

	time(&start);
	while (i < (X * Y))
		sum += matrice[i++];
	time(&end);
	printf("le temps de traitement de la matrice 1D est de: %ld\n", end - start);
	free(matrice);
	(void) sum;
	return (end - start);
}