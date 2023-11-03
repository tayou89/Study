#ifndef BINARY_TREE_H
# define BINARY_TREE_H

# include <stdio.h>
# include <stdlib.h>

typedef int	BTdata;

typedef	struct binary_tree_node
{
	BTdata					data;
	struct binary_tree_node	*left;
	struct binary_tree_node	*right;
}	tree_node;

typedef void	(*function_pointer)(BTdata); 

tree_node	*make_tree_node(void);
void		set_data(tree_node *node, BTdata data);
BTdata		get_data(tree_node *node);
tree_node	*get_left_subtree(tree_node *node);
tree_node	*get_right_subtree(tree_node *node);
void		make_left_subtree(tree_node *main, tree_node *sub);
void		make_right_subtree(tree_node *main, tree_node *sub);
void		free_subtree(tree_node *node);
void		print_data(BTdata data);
void		print_all(tree_node *node);

void		inorder_traverse(tree_node *node, function_pointer action);
void		preorder_traverse(tree_node *node, function_pointer action);
void		postorder_traverse(tree_node *node, function_pointer action);

void		ChangeLeftSubTree(tree_node *main, tree_node *sub);
void		ChangeRightSubTree(tree_node *main, tree_node *sub);
tree_node	*RemoveLeftSubTree(tree_node *node);
tree_node	*RemoveRightSubTree(tree_node *node);

#endif
