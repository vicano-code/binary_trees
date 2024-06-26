#include "binary_trees.h"

/**
 * binary_tree_delete -  deletes an entire binary tree
 * @tree: pointer to the root node
 * Return: Nothing
 */
void binary_tree_delete(binary_tree_t *tree)
{
	/*binary_tree_t *tmp;*/

	if (tree == NULL)
		return;
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);
	free(tree);
}
