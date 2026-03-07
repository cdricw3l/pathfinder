#include "include/pathfinder.h"

void tree_exploration(t_node *node)
{
    if (!node)
        return ;
    tree_exploration(node->children_left);
    printf("Node value: %d\n", node->value);
    tree_exploration(node->children_right);
}

void init_node(t_node *node, int value)
{
    node->value = value;
    node->children_left = NULL;
    node->children_right = NULL;
    node->parent_left = NULL;
    node->parent_right = NULL;
}

int main(void)
{
    t_node node_1;
    t_node node_2;
    t_node node_3;

    init_node(&node_1, 1);
    init_node(&node_2, 2);
    init_node(&node_3, 3);

    node_1.children_left = &node_2;
    node_1.children_right = &node_3;

    tree_exploration(&node_1);

}