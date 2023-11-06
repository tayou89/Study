#include "binary_search_tree.h"
#include <stdio.h>

void	print_tree_map(BTNode *node, int i);

int	main(void)
{
	BTNode	*bstRoot;

	bst_init(&bstRoot);
	BSTInsert(&bstRoot, 1);
	BSTInsert(&bstRoot, 2);
	BSTInsert(&bstRoot, 3);
	BSTInsert(&bstRoot, 4);
	BSTInsert(&bstRoot, 5);
	BSTInsert(&bstRoot, 6);
	BSTInsert(&bstRoot, 7);
	BSTInsert(&bstRoot, 8);
	BSTInsert(&bstRoot, 9);

	print_all(bstRoot); printf("\n");
	print_tree_map(bstRoot, 1);
	return (0);
}

void	print_tree_map(BTNode *node, int i)
{
	if (node == NULL)
		return ;
	printf("Later: %d, ", i);
	printf("Node->data: %d\n", node->data);
	print_tree_map(get_left_subtree(node), i + 1);
	print_tree_map(get_right_subtree(node), i + 1);
}
