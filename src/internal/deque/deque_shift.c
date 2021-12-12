#include "internal/deque.h"

int	deque_shift(deque *d)
{
	deque_node	*cursor;

	debug("----- %s", __FUNCTION__);
	if (!d)
		return (DEQUE_ERROR_DEQUE_NULL);
	if (!d->head)
		return (DEQUE_ERROR_DEQUE_EMPTY);
	cursor = d->head;
	while (cursor->next)
		cursor = cursor->next;
	cursor->prev->next = NULL;
	cursor->prev = NULL;
	free(cursor);
	d->len--;
	return (DEQUE_SUCCESS);
}
