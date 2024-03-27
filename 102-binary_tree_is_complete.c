#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: the height or NULL if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return ((left_height > right_height) ? (left_height + 1) :
		(right_height + 1));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree
 * Return: 1-complete, 0-NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t *queue[1024];
	size_t front = 0, rear = 0;
	binary_tree_t *current;

	if (tree == NULL)
		return (0);
	/* enqueue the root */
	queue[rear++] = (binary_tree_t *)tree;

	/* loop until queue empty */
	while (front < rear)
	{
		current = queue[front++]; /*dequeue a node*/
		if (current == NULL)
		{
			while (front < rear)
			{
				if (queue[front++] != NULL)
					return (0);
			}
			return (1);
		}
		/* enqueue left child */
		queue[rear++] = current->left;
		/* enqueue right child */
		queue[rear++] = current->right;
	}
	return (1);
}
