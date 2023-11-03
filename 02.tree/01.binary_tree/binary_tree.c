#include "binary_tree.h"

tree_node	*make_tree_node(void)
{
	tree_node	*new_node;

	new_node = (tree_node *) malloc(sizeof(tree_node));
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}

void	set_data(tree_node *node, Data data)
{
	node->data = data;
}

Data	get_data(tree_node *node)
{
	return (node->data);
}

tree_node	*get_left_subtree(tree_node *node)
{
	return (node->left);
}

tree_node	*get_right_subtree(tree_node *node)
{
	return (node->right);
}

void	make_left_subtree(tree_node	*main, tree_node *sub)
{
	if (main->left != NULL)
		free_subtree(main->left);
	main->left = sub;
}

void	make_right_subtree(tree_node	*main, tree_node *sub)
{
	if (main->right != NULL)
		free_subtree(main->left);
	main->right = sub;
}

void	free_subtree(tree_node *node)
{
	if (node == NULL)
		return ;
	free_subtree(node->left);
	free_subtree(node->right);
	free(node);
}

void	print_data(Data data)
{
	printf("node->data: %d\n", data);
}
