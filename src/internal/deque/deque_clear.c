#include "internal/deque.h"
#include "test/expect.h"
#include "test/testing.h"

size_t	deque_clear(deque *d, int (*fn)(void *))
{
	deque_node	*cursor;
	char			*t;
	size_t	len;

	debug("----- %s", __FUNCTION__);
	if (!d)
		return (DEQUE_ERROR_DEQUE_NULL);
	if (deque_isempty(d))
		return (0);
	cursor = d->head;
	len = 0;
	while (cursor)
	{
		cursor = cursor->next;
		len += deque_pop(d, fn);
	}
	memset(d, 0, sizeof(deque));
	return (len);
}
