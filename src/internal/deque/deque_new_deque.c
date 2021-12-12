#include "internal/deque.h"

deque	*deque_new(void)
{
	deque	*d;

	debug("----- %s", __FUNCTION__);
	d = (deque *)malloc(sizeof(deque));
	memset(d, 0, sizeof(deque));
	if (!d)
		return (NULL);
	d->head = NULL;
	d->len = 0;
	return (d);
}
