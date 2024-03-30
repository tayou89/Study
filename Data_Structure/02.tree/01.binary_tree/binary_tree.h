#ifndef BINARY_TREE_H
# define BINARY_TREE_H

# include <stdio.h>
# include <stdlib.h>

typedef int	Data;

typedef	struct binary_tree_node
{
	Data					data;
	struct binary_tree_node	*left;
	struct binary_tree_node	*right;
}	tree_node;

typedef void	(*function_pointer)(Data); 

tree_node	*make_tree_node(void);
void		set_data(tree_node *node, Data data);
Data		get_data(tree_node *node);
tree_node	*get_left_subtree(tree_node *node);
tree_node	*get_right_subtree(tree_node *node);
void		make_left_subtree(tree_node *main, tree_node *sub);
void		make_right_subtree(tree_node *main, tree_node *sub);
void		free_subtree(tree_node *node);
void		print_data(Data data);

#endif
