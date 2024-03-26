#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree);

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree 
 * Return: the balane factor or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);
	left_height = 1;
	right_height = 1;
	left_height += binary_tree_height(tree->left);
	right_height += binary_tree_height(tree->right);
	return (left_height - right_height);
}
