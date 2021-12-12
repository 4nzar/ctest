#include "ctest/ctest.h"

ctest	*ctest_create(void)
{
	ctest	*ct;

	debug("----- %s", __FUNCTION__);
	ct = (ctest *)malloc(sizeof(ctest));
	if (!ct)
		return (NULL);
	memset(ct, 0, sizeof(ctest));
	ct->path = NULL;
	ct->suites = deque_new();
	return (ct);
}

