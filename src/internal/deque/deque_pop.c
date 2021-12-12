#include "internal/deque.h"

int	deque_pop(deque *d, int (*fn)(void *))
{
	deque_node	*cursor;

	debug("----- %s", __FUNCTION__);
	if (!d)
		return (0);
	if (!d->head)
		return (0);
	cursor = d->head->next;
	d->head->prev = NULL;
	d->head->next = NULL;
	if (d->head->data)
		fn(d->head->data);
	d->head->data = NULL;
	free(d->head);
	d->head = cursor;
	d->len--;
	return (1);
}
