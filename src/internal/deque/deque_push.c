#include "internal/deque.h"

int	deque_push(deque *d, void *data)
{
	deque_node	*node;

	debug("----- %s", __FUNCTION__);
	if (!d)
		return (DEQUE_ERROR_DEQUE_NULL);
	node = deque_new_node(data);
	if (!node)
		return (DEQUE_ERROR_MEMORY_ALLOCATION);
	node->next = d->head;
	if (d->head)
		d->head->prev = node;
	d->head = node;
	d->len++;
	return (DEQUE_SUCCESS);
}
