#include "binary_tree.h"

tree_node	*make_tree_node(void)
{
	tree_node	*new_node;

	new_node = (tree_node *) malloc(sizeof(tree_node));
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}

void	set_data(tree_node *node, BTdata data)
{
	node->data = data;
}

BTdata	get_data(tree_node *node)
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

void	inorder_traverse(tree_node *node, function_pointer action)
{
	if (node == NULL)
		return ;
	inorder_traverse(node->left, action);
	action(node->data);
	inorder_traverse(node->right, action);
}

void	preorder_traverse(tree_node *node, function_pointer action)
{
	if (node == NULL)
		return ;
	action(node->data);
	preorder_traverse(node->left, action);
	preorder_traverse(node->right, action);
}

void	postorder_traverse(tree_node *node, function_pointer action)
{
	if (node == NULL)
		return ;
	postorder_traverse(node->left, action);
	postorder_traverse(node->right, action);
	action(node->data);
}

void	print_data(BTdata data)
{
	printf("node->data: %d\n", data);
}

void	print_all(tree_node *node)
{
	inorder_traverse(node, print_data);
}

void	ChangeLeftSubTree(tree_node *main, tree_node *sub)
{
	main->left = sub;
}

void	ChangeRightSubTree(tree_node *main, tree_node *sub)
{
	main->right = sub;
}

tree_node	*RemoveLeftSubTree(tree_node *node)
{
	tree_node	*nodeToRemove;

	nodeToRemove = node->left;
	node->left = NULL;
	return (nodeToRemove);
}

tree_node	*RemoveRightSubTree(tree_node *node)
{
	tree_node	*nodeToRemove;

	nodeToRemove = node->right;
	node->right = NULL;
	return (nodeToRemove);
}
