#include "AVL_rebalance.h"

static int		GetHeightDiff(tree_node *root);
static int		GetHeight(tree_node *root);
static tree_node	*RotateLL(tree_node *root);
static tree_node	*RotateLR(tree_node *root);
static tree_node	*RotateRR(tree_node *root);
static tree_node	*RotateRL(tree_node *root);

tree_node	*AVLRebalance(tree_node **root)
{
	int	heightDiff = GetHeightDiff(*root);

	if (heightDiff > 1)
	{
		if (GetHeightDiff(get_left_subtree(*root)) > 0)
			*root = RotateLL(*root);
		else
			*root = RotateLR(*root);
	}
	if (heightDiff < -1)
	{
		if (GetHeightDiff(get_right_subtree(*root)) < 0)
			*root = RotateRR(*root);
		else
			*root = RotateRL(*root);
	}
	return (*root);
}

static int	GetHeightDiff(tree_node *root)
{
	int	leftTreeHeight;
	int	rightTreeHeight;

	if (root == NULL)
		return (0);
	leftTreeHeight = GetHeight(get_left_subtree(root));
	rightTreeHeight = GetHeight(get_right_subtree(root));
	return (leftTreeHeight - rightTreeHeight);
}

static int	GetHeight(tree_node *root)
{
	int	leftTreeHeight;
	int	rightTreeHeight;

	if (root == NULL)
		return (0);
	leftTreeHeight = GetHeight(get_left_subtree(root));
	rightTreeHeight = GetHeight(get_right_subtree(root));
	if (leftTreeHeight > rightTreeHeight)
		return (leftTreeHeight + 1);
	else
		return (rightTreeHeight + 1);
}

tree_node	*RotateLL(tree_node *root)
{
	tree_node	*leftSubTree = get_left_subtree(root);

	ChangeLeftSubTree(root, get_right_subtree(leftSubTree));
	ChangeRightSubTree(leftSubTree, root);
	return (leftSubTree);
}

tree_node	*RotateLR(tree_node *root)
{
	tree_node	*leftSubTree = get_left_subtree(root);

	ChangeLeftSubTree(root, get_left_subtree(leftSubTree));
	ChangeLeftSubTree(leftSubTree, root);
	return (leftSubTree);
}

tree_node	*RotateRR(tree_node *root)
{
	tree_node	*rightSubTree = get_right_subtree(root);

	ChangeRightSubTree(root, get_left_subtree(rightSubTree));
	ChangeLeftSubTree(rightSubTree, root);
	return (rightSubTree);
}

tree_node	*RotateRL(tree_node *root)
{
	tree_node	*rightSubTree = get_right_subtree(root);

	ChangeRightSubTree(root, get_right_subtree(rightSubTree));
	ChangeRightSubTree(rightSubTree, root);
	return (rightSubTree);
}
