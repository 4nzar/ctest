#include "internal/deque.h"

size_t	deque_size(deque const *d)
{
	debug("----- %s", __FUNCTION__);
	if (!d)
		return (0);
	return (d->len);
}
