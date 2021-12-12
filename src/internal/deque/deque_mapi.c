#include "internal/deque.h"

int	deque_mapi(deque *d, deque_node *(*cb)(unsigned int,deque_node *node))
{
	deque_node	*cursor;
	size_t	len;

	debug("----- DEQUE MAPI");
	if (!d)
		return (DEQUE_ERROR_DEQUE_NULL);
	if (!d->head)
		return (DEQUE_ERROR_DEQUE_EMPTY);
	cursor = d->head;
	len = 0;
	while (cursor)
	{
		cursor = cb(len, cursor);
		if (!cursor)
			return (DEQUE_ERROR_NODE_NULL);
		cursor = cursor->next;
	}
	return (len);
}
