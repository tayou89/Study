#include "binary_search_tree.h"

static BTNode	*GetParentNodeToInsert(BTNode *currentNode, BSTData data);
static void		InsertNewNode(BTNode **root, BTNode *parentNode, BTNode *newNode, BSTData data);
static BTNode	*GetNodeToRemove(BTNode *root, BTNode **parentNode, BSTData target);
static void		RemoveZeroSubTreeNode(BTNode *parentNode, BTNode *nodeToRemove);
static void		RemoveOneSubTreeNode(BTNode *parentNode, BTNode *nodeToRemove);
static void		RemoveTwoSubTreeNode(BTNode **nodeToRemove);

void	bst_init(BTNode	**bst_root)
{
	*bst_root = NULL;
}

BSTData	BSTGetNodeData(BTNode *bst_node)
{
	return (get_data(bst_node));
}

void	BSTInsert(BTNode **root, BSTData data)
{
	BTNode	*currentNode = *root;
	BTNode	*parentNode = NULL;
	BTNode	*newNode = NULL;

	parentNode = GetParentNodeToInsert(currentNode, data);
	if (*root != NULL && parentNode == NULL)
		return ;
	newNode = make_tree_node();
	set_data(newNode, data);
	InsertNewNode(root, parentNode, newNode, data);
}

static BTNode	*GetParentNodeToInsert(BTNode *currentNode, BSTData data)
{
	BTNode	*parentNode = NULL;

	while (currentNode != NULL)
	{
		parentNode = currentNode;
		if (data == get_data(currentNode))
			return (NULL);
		else if (data < get_data(currentNode))
			currentNode = get_left_subtree(currentNode);
		else
			currentNode = get_right_subtree(currentNode);
	}
	return (parentNode);
}

static void	InsertNewNode(BTNode **root, BTNode *parentNode, BTNode *newNode, BSTData data)
{
	if (*root == NULL)
		*root = newNode;
	else
	{
		if (data < get_data(parentNode))
			make_left_subtree(parentNode, newNode);
		else
			make_right_subtree(parentNode, newNode);
	}
}

BTNode	*BSTSearch(BTNode *root, BSTData data)
{
	BTNode	*currentNode = root;
	BSTData	currentNodeData;

	while (currentNode != NULL)
	{
		currentNodeData = get_data(currentNode);
		if (currentNodeData == data)
			return (currentNode);
		else if (data < currentNodeData)
			currentNode = get_left_subtree(currentNode);
		else
			currentNode = get_right_subtree(currentNode);
	}
	return (NULL);
}

BTNode	*BSTRemove(BTNode **root, BSTData target)
{
	BTNode	*virtualRoot = NULL;
	BTNode	*parentNode = NULL;
	BTNode	*nodeToRemove = NULL;

	nodeToRemove = GetNodeToRemove(*root, &parentNode, target);
	if (nodeToRemove == NULL)
		return (NULL);
	virtualRoot = (BTNode *) malloc(sizeof(BTNode));
	ChangeRightSubTree(virtualRoot, *root);
	if (nodeToRemove == *root)
		parentNode = virtualRoot;
	if (get_right_subtree(nodeToRemove) == NULL && 
		get_left_subtree(nodeToRemove) == NULL)
		RemoveZeroSubTreeNode(parentNode, nodeToRemove);
	else if (get_right_subtree(nodeToRemove) == NULL || 
			get_left_subtree(nodeToRemove) == NULL)
		RemoveOneSubTreeNode(parentNode, nodeToRemove);
	else
		RemoveTwoSubTreeNode(&nodeToRemove);
	if (get_right_subtree(virtualRoot) != *root)
		*root = get_right_subtree(virtualRoot);
	free(virtualRoot);
	return (nodeToRemove);
}

static BTNode	*GetNodeToRemove(BTNode *root, BTNode **parentNode, BSTData target)
{
	BTNode	*currentNode = root;

	while (currentNode != NULL && target != get_data(currentNode))
	{
		*parentNode = currentNode;
		if (target < get_data(currentNode))
			currentNode = get_left_subtree(currentNode);
		else
			currentNode = get_right_subtree(currentNode);
	}
	return (currentNode);
}

static void	RemoveZeroSubTreeNode(BTNode *parentNode, BTNode *nodeToRemove)
{
	if (get_left_subtree(parentNode) == nodeToRemove)
		RemoveLeftSubTree(parentNode);
	else
		RemoveRightSubTree(parentNode);
}

static void	RemoveOneSubTreeNode(BTNode *parentNode, BTNode *nodeToRemove)
{
	if (get_left_subtree(nodeToRemove) != NULL)
		ChangeLeftSubTree(parentNode, get_left_subtree(nodeToRemove));
	else
		ChangeRightSubTree(parentNode, get_right_subtree(nodeToRemove));
}

static void	RemoveTwoSubTreeNode(BTNode **nodeToRemove)
{
	BTNode	*nodeToReplace;
	BTNode	*parentNode;
	BSTData	backupData;
	
	parentNode = *nodeToRemove;
	nodeToReplace = get_right_subtree(*nodeToRemove);
	while (get_left_subtree(nodeToReplace) != NULL)
	{
		parentNode = nodeToReplace;
		nodeToReplace = get_left_subtree(nodeToReplace);
	}
	backupData = get_data(*nodeToRemove);
	set_data(*nodeToRemove, get_data(nodeToReplace));
	if (get_left_subtree(parentNode) == nodeToReplace)
		ChangeLeftSubTree(parentNode, get_right_subtree(nodeToReplace));
	else
		ChangeRightSubTree(parentNode, get_right_subtree(nodeToReplace));
	*nodeToRemove = nodeToReplace;
	set_data(*nodeToRemove, backupData);
}
