#ifndef EXPRESSION_TREE_H
# define EXPRESSION_TREE_H

# include <ctype.h>

# include "binary_tree.h"
# include "stack.h"

tree_node	*make_expression_tree(char expression[]);
int			calculate_expression_tree(tree_node *node);

#endif
