#include "../include/pathfinder.h"

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

t_path_node *get_tree_node(t_points **points, int x, int y)
{
    t_points p;
    t_path_node *root;

    if (x < 0 || y < 0 || x >= X  || y >= Y)
        return (NULL);

    p.x = x;
    p.y = y;

    if(is_on(points, &p))
        return (NULL);

    root = new_node(&p);
    if (!root)
        return (NULL);
    add_points_as_processed(points, &p);
    display_points(points);

    root->n1 = get_tree_node(points, x - 1, y);
    root->n2 = get_tree_node(points, x, y - 1);
    root->n3 = get_tree_node(points, x, y + 1);
    root->n4 = get_tree_node(points, x + 1, y);

    return(root);
}

int main(void)
{

    t_points **points;
    t_path_node *root;
    
    points = malloc(sizeof(t_points *) * (X * Y));
    if (!points)
        return (1);
    memset(points, 0, sizeof(t_points *) * (X * Y));
    root = get_tree_node(points, 1, 2);
    if (root)
        printf("root OK\n");
    
    return(0);
}