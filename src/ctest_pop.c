#include "ctest/ctest.h"

int	ctest_pop(ctest *ct)
{
	int ret;

	debug("----- %s", __FUNCTION__);
	if (!ct)
		return (0);
	ret = deque_pop(ct->suites, (void *)&suite_free);
	return (ret);
}
