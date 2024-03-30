#ifndef BINARY_SEARCH_TREE_H
# define BINARY_SEARCH_TREE_H

# include "binary_tree.h"

typedef BTdata		BSTData;
typedef tree_node	BTNode;

void	bst_init(BTNode **bst_root);
BSTData	BSTGetNodeData(BTNode *bst_node);
void	BSTInsert(BTNode **root, BSTData data);
BTNode	*BSTSearch(BTNode *root, BSTData data);
BTNode	*BSTRemove(BTNode **root, BSTData target);

#endif
