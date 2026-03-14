#ifndef PATHFINDER_H
#define PATHFINDER_H



#include "../cost_and_perf/cost_and_perf.h"
#include "../srcs/points/points.h"
#include "../srcs/tree/tree.h"

#ifndef X
    #define X 30000
#endif

#ifndef Y
    #define Y 40000
#endif


#define START	printf("Start fonction %s\n", __func__)
#define END		printf("End fonction %s\n", __func__)


typedef struct s_node_1
{
	int			value;
	t_points	points;
	void		*parent_right;
	void		*parent_left;
	void		*children_right;
	void		*children_left;

} t_node_1;



#endif