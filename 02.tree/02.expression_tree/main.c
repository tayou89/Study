#include "expression_tree.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void	check_argc(int argc);
void	make_postfix_expression(char *expression);
bool	bigger_operator(char operator_1, char operator_2);
int		get_operator_number(char operator);

int	main(int argc, char *argv[])
{
	char		*expression;
	tree_node	*expression_tree;

	check_argc(argc);
	expression = argv[1];
	make_postfix_expression(expression);
	printf("postfix_expression: %s\n", expression);
	expression_tree = make_expression_tree(expression);
	printf("=================inorder_traverse=================\n\n");
	inorder_traverse(expression_tree, print_data);
	printf("\n");
	printf("=================preorder_traverse=================\n\n");
	preorder_traverse(expression_tree, print_data);
	printf("\n");
	printf("=================postorder_traverse=================\n\n");
	postorder_traverse(expression_tree, print_data);
	printf("\n");
	printf("calculate_result: %d\n", calculate_expression_tree(expression_tree));
	return (0);
}

void	check_argc(int argc)
{
	if (argc != 2)
	{
		printf("Wrong Argument.\n");
		printf("Type mathematical expression.\n");
		exit(0);
	}
}

void	make_postfix_expression(char *expression)
{
	char	copy_expression[strlen(expression)];
	Stack	stack;
	char	*popup_data;
	int		j;

	strcpy(copy_expression, expression);
	memset(expression, 0, strlen(expression));
	stack_init(&stack);
	j = 0;
	for (int i = 0; copy_expression[i] != '\0'; i++)
	{
		if (isdigit(copy_expression[i]) != 0)
			expression[j++] = copy_expression[i];
		else if (copy_expression[i] == ' ')
			continue ;
		else
		{
			switch(copy_expression[i])
			{
			case '(':
				push(&stack, &copy_expression[i]);
				break ;
			case ')':
				popup_data = (char *) pop_up(&stack);
				while (*popup_data != '(')
				{
					expression[j++] = *popup_data;
					popup_data = (char *) pop_up(&stack);
				}
				break ;
			case '+': case '-':
			case '*': case '/':
				while (!is_empty(&stack) &&
						bigger_operator(*popup_data, copy_expression[i]) == true)
				{
					popup_data = (char *) pop_up(&stack);
					expression[j++] = *popup_data;
					popup_data = (char *) peek(&stack);
				}
				push(&stack, &copy_expression[i]);
				break ;
			}
		}
	}
	while (!is_empty(&stack))
	{
		popup_data = (char *) pop_up(&stack);
		expression[j++] = *popup_data;
	}
}

bool	bigger_operator(char operator_1, char operator_2)
{
	int	operator_number_1 = get_operator_number(operator_1);
	int	operator_number_2 = get_operator_number(operator_2);
	
	if (operator_number_1 >= operator_number_2)
		return (true);
	else
		return (false);

}

int	get_operator_number(char operator)
{
	switch (operator)
	{
	case '*':
	case '/':
		return (5);
	case '+':
	case '-':
		return (3);
	case '(':
		return (1);
	}
	return (-1);
}
