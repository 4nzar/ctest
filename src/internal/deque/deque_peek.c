#include "internal/deque.h"

deque_node	*deque_peek(deque const *d)
{
	deque_node	*node;

	debug("----- %s", __FUNCTION__);
	if (!d)
		return (NULL);
	node = d->head;
	return (node);
}
