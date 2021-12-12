#include "internal/deque.h"

int	deque_map(deque *d, deque_node *(*cb)(deque_node *node))
{
	deque_node	*cursor;
	size_t	len;

	debug("----- %s", __FUNCTION__);
	if (!d)
		return (DEQUE_ERROR_DEQUE_NULL);
	if (!d->head)
		return (DEQUE_ERROR_DEQUE_EMPTY);
	cursor = d->head;
	len = 0;
	while (cursor)
	{
		cursor = cb(cursor);
		if (!cursor)
		{
			return (DEQUE_ERROR_NODE_NULL);
		}
		cursor = cursor->next;
	}
	return (len);
}
