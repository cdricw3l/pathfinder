/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 00:11:08 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/14 01:01:19 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "points.h"

void display_points(t_points **points)
{
    size_t      i;
    t_points    **ptr;

    ptr = points;
    i = 0;
    while (*ptr)
    {
        printf("\nNode %zu:\nx = %d y = %d\n", i, (*ptr)->x, (*ptr)->y);
        i++;
        ptr++;
    }
    
}

void add_points_as_processed(t_points **points, t_points *p)
{
    t_points **ptr;

    ptr = points;
    while (*ptr)
        ptr++;
    *ptr = p;
}

int is_on(t_points **points, t_points *p)
{
    t_points **ptr;

    if (!points)
        return(0);
    ptr = points;
    while (*ptr)
    {
        if((*ptr)->x == p->x && (*ptr)->y == p->y)
            return (1);
        ptr++;
    }
    return (0);
}

