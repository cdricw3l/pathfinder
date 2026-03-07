#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <unistd.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_node
{
	int		value;
	void	*parent_right;
	void	*parent_left;
	void	*children_right;
	void	*children_left;

} t_node;

#endif