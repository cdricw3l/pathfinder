#include "include/pathfinder.h"

#define X 300
#define Y 400

t_path_node *get_node(int *mat, int x, int y)
{
    t_path_node *node;

    (void)mat;
    node = malloc(sizeof(node));
    if(!node)
        return (NULL);
    node->points.x = x;
    node->points.y = y;
    node->n1 = NULL;
    node->n2 = NULL;
    node->n3 = NULL;
    return (node);
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

void memory_2D_cost(void)
{
    int **matrice;
    int *line;

    matrice = malloc(sizeof(int *));
    if (!matrice)
        return ;
    line  = malloc(sizeof(int));
    if (!line)
    {
        free(matrice);
        return ;
    }   
    printf("taille Theorique: matrice = (%lu * %d) + (%lu * %d) = %lu\n", sizeof(int *),X, sizeof(int), Y, (sizeof(int *) * X) + (sizeof(int) * Y));
    printf("taille Reel: matrice = (%ld * %d) +  (%ld * %d) = %ld\n",malloc_size(matrice),X,malloc_size(line), Y ,(malloc_size(matrice) * X) + (malloc_size(line) * Y));

    free(line);
    free(matrice);
}

void memory_1D_cost(void)
{
    int *matrice;

    matrice = malloc(sizeof(int));
    if (!matrice)
        return ;

    printf("taille Theorique: matrice = %lu * (%d * %d) = %lu\n", sizeof(int), X, Y, sizeof(int) * (X * Y));
    printf("taille Reel: matrice  = %lu * (%d * %d) = %lu\n", malloc_size(matrice), X, Y, malloc_size(matrice) * (X *Y));
    free(matrice);
}


int main(void)
{
    //int *mat;
    memory_2D_cost();
    memory_1D_cost();


    // mat = get_matrice(X,Y);
    // if (!mat)
    //     return (1);
    // display_matrice(mat,X, Y);

    //free(mat);
    return(0);
}