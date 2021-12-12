#include "internal/deque.h"

int	deque_isempty(deque const *d)
{
	debug("----- %s", __FUNCTION__);
	return (d->len == 0);
}
