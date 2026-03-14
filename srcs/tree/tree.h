/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 00:58:00 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/14 01:15:14 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
#define TREE_H

#include <unistd.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../points/points.h"

typedef struct s_path_node
{
	int					value;
	t_points			points;
	struct s_path_node	*n1;
	struct s_path_node	*n2;
	struct s_path_node	*n3;
	struct s_path_node	*n4;

} t_path_node;

void        display_node(t_path_node *node, size_t idx);
t_path_node *new_node(t_points *p);

#endif