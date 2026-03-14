/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 00:11:47 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/14 01:05:10 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
#define POINT_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct s_points
{
	int x;
	int y;

} t_points;

int		is_on(t_points **points, t_points *p);
void	add_points_as_processed(t_points **points, t_points *p);
void	display_points(t_points **points);

#endif