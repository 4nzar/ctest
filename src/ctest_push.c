#include "ctest/ctest.h"

int	ctest_push(ctest *ct, suite *s)
{
	int	ret;

	debug("----- %s", __FUNCTION__);
	if (!ct)
		return (0);
	ret = deque_push(ct->suites, (void *)s);
	return (ret);
}
