#include "binary_tree.h"

void	travel_tree_node(tree_node *node, void (*ft_pointer) (Data));

int	main(void)
{
	tree_node	*node_A;
	tree_node	*node_B;
	tree_node	*node_C;
	tree_node	*node_D;

	node_A = make_tree_node();
	node_B = make_tree_node();
	node_C = make_tree_node();
	node_D = make_tree_node();

	set_data(node_A, 1);
	set_data(node_B, 2);
	set_data(node_C, 3);
	set_data(node_D, 4);

	make_left_subtree(node_A, node_B);
	make_right_subtree(node_A, node_C);
	make_left_subtree(node_B, node_D);

	travel_tree_node(node_A, print_data);
	return (0);
}

void	travel_tree_node(tree_node *node, function_pointer action)
{
	if (node == NULL)
		return ;
	travel_tree_node(node->left, action);
	action(node->data);
	travel_tree_node(node->right, action);
}
