#include "expression_tree.h"

tree_node	*make_expression_tree(char expression[])
{
	tree_node	*node;
	Stack		stack;

	stack_init(&stack);
	for (int i = 0; expression[i] != '\0'; i++)
	{
		node = make_tree_node();
		if (isdigit(expression[i]))
			set_data(node, expression[i] - '0');
		else
		{
			set_data(node, expression[i]);
			make_right_subtree(node, (tree_node *) pop_up(&stack));
			make_left_subtree(node, (tree_node *) pop_up(&stack));
		}
		push(&stack, node);
	}
	return ((tree_node *) pop_up(&stack));
}

int	calculate_expression_tree(tree_node *node)
{
	int	number_1, number_2;

	if (get_left_subtree(node) == NULL && get_right_subtree(node) == NULL)
		return (get_data(node));
	number_1 = calculate_expression_tree(get_left_subtree(node));
	number_2 = calculate_expression_tree(get_right_subtree(node));
	switch(get_data(node))
	{
	case '+':
		return (number_1 + number_2);
	case '-':
		return (number_1 - number_2);
	case '*':
		return (number_1 * number_2);
	case '/':
		return (number_1 / number_2);
	}
	return (0);
}
