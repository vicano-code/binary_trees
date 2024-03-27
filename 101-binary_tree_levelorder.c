#include "binary_trees.h"

/**
 * binary_tree_levelorder - binary tree level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * Return: Nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *queue[1024];
	size_t front = 0, rear = 0;
	binary_tree_t *current;

	if (tree == NULL || func == NULL)
		return;
	/* enqueue the root */
	queue[rear++] = (binary_tree_t *)tree;

	/* loop until queue empty */
	while (front < rear)
	{
		current = queue[front++]; /*dequeue a node*/
		func(current->n); /*call function for current node*/

		/* enqueue left child if exists */
		if (current->left)
			queue[rear++] = current->left;
		/* enqueue right child if exists */
		if (current->right)
			queue[rear++] = current->right;
	}
}
