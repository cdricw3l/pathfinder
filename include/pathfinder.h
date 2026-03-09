#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <unistd.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <malloc/malloc.h>
#include "../cost_and_perf/cost_and_perf.h"

typedef struct s_points
{
	int x;
	int y;

} t_points;


typedef struct s_node_1
{
	int			value;
	t_points	points;
	void		*parent_right;
	void		*parent_left;
	void		*children_right;
	void		*children_left;

} t_node_1;

typedef struct s_path_node
{
	int					value;
	t_points			points;
	struct s_path_node	*n1;
	struct s_path_node	*n2;
	struct s_path_node	*n3;

} t_path_node;

#endif