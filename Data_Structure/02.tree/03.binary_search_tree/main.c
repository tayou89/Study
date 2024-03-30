#include "binary_search_tree.h"
#include <stdio.h>

int	main(void)
{
	BTNode	*bstRoot;
	BTNode	*tempNode;

	bst_init(&bstRoot);
	BSTInsert(&bstRoot, 10);
	BSTInsert(&bstRoot, 3);
	BSTInsert(&bstRoot, 2);
	BSTInsert(&bstRoot, 7);
	BSTInsert(&bstRoot, 16);
	BSTInsert(&bstRoot, 23);
	BSTInsert(&bstRoot, 8);
	BSTInsert(&bstRoot, 13);
	BSTInsert(&bstRoot, 22);
	BSTInsert(&bstRoot, 11);
	BSTInsert(&bstRoot, 50);

	print_all(bstRoot); printf("\n");

	tempNode = BSTRemove(&bstRoot, 7);
	free(tempNode);
	tempNode = NULL;
	printf("7 is removed.\n");
	print_all(bstRoot); printf("\n");

	tempNode = BSTRemove(&bstRoot, 50);
	free(tempNode);
	tempNode = NULL;
	printf("50 is removed.\n");
	print_all(bstRoot); printf("\n");

	tempNode = BSTRemove(&bstRoot, 10);
	free(tempNode);
	tempNode = NULL;
	printf("10 is removed.\n");
	print_all(bstRoot); printf("\n");
	
	tempNode = BSTRemove(&bstRoot, 8);
	free(tempNode);
	tempNode = NULL;
	printf("8 is removed.\n");
	print_all(bstRoot); printf("\n");

	tempNode = BSTRemove(&bstRoot, 11);
	free(tempNode);
	tempNode = NULL;
	printf("11 is removed.\n");
	print_all(bstRoot); printf("\n");

	return (0);
}
