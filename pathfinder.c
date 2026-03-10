#include "include/pathfinder.h"

int is_on(t_points *points, size_t idx,int x, int y)
{
    size_t i;

    i = 0;
    if (!points)
        return(0);
    while (i <= idx)
    {
        if(points[i].x == x && points[i].y == y)
            return (1);
        
        i++;
    }
    return (0);
}

t_path_node *get_node(t_points *points, int x, int y, size_t *idx)
{
    t_path_node *node;
    t_points p;

    if (x < 0 || y < 0 || x > X - 1  || y > Y - 1)
    {
        return (NULL);
    }
    printf("x1: %d, y1: %d, idx: %zu\n",x,y, *idx);
    if(is_on(points,*idx, x, y))
    {
        printf("is on \n");
        return (NULL);
    }
    printf("x3: %d, y3: %d, idx: %zu\n",x,y,* idx);
    
    node = malloc(sizeof(t_path_node));
    if(!node)
        return (NULL);
    
    p.x = x;
    p.y = y;
    node->points = p;
    points[*idx] = node->points;
    (*idx)++;
    printf("here\n");

    node->n1 = get_node(points ,node->points.x, node->points.y + 1, idx);
    node->n2 = get_node(points ,node->points.x + 1, node->points.y, idx);
    node->n3 = get_node(points ,node->points.x - 1, node->points.y, idx);
    node->n4 = get_node(points ,node->points.x , node->points.y - 1, idx);
    return(node);
}

void    display_matrice(int *mat, int x_max, int y_max)
{
    int i;
    int nl;

    i = 0;
    nl = 0;
    while (i < (x_max * y_max))
    {
        printf("%d ", mat[i]);
        if (nl == y_max - 1)
        {
            printf("\n");
            nl = 0;
        }
        else
            nl++;
        i++;
    }
}


int main(void)
{

    t_points *points;
    t_path_node *node;
    size_t idx;

    idx = 0;
    points = malloc(sizeof(t_points) * (X * Y));
    if (!points)
        return(1);
    points = NULL;
    node = get_node(points, 1, 2,  &idx);
    assert(node);
    free(points);
    return(0);
}