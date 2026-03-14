/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 00:58:25 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/14 01:07:56 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

t_path_node *new_node(t_points *p)
{
    t_path_node *node;

    node = malloc(sizeof(t_path_node));
    if(!node)
        return (NULL);
    node->points = *p;
    node->n1 = NULL;
    node->n2 = NULL;
    node->n3 = NULL;
    node->n4 = NULL;
    return (node);
}

void display_node(t_path_node *node, size_t idx)
{
    if (idx == 0)
        printf("\nROOT: %p\n", node);
    else
        printf("\nNode %zu: %p\n", idx,node);

    printf("x: %d, y: %d\n", node->points.x, node->points.y);
    printf("Children 1: %p\n", node->n1);
    printf("Children 2: %p\n", node->n2);
    printf("Children 3: %p\n", node->n3);
    printf("Children 4: %p\n", node->n4);
}
