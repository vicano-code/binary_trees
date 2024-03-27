#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node
 * Return: pointer to the created node or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *tmp;

	if (parent == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		tmp = parent->right;
		parent->right = binary_tree_node(parent, value);
		parent->right->right = tmp;
	}
	else
		parent->right = binary_tree_node(parent, value);

	return (parent->right);
}
