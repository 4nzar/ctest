#include "internal/deque.h"

deque_node	*deque_new_node(void *data)
{
	deque_node	*node;

	debug("----- %s", __FUNCTION__);
	node = (deque_node *)malloc(sizeof(deque_node));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
