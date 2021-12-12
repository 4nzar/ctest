#include "ctest/ctest.h"

void	ctest_free(ctest *ct)
{
	int ret;

	debug("----- %s", __FUNCTION__);
	if (!ct)
		return ;
	if (ct->suites)
	{
		ret = deque_clear(ct->suites, (void *)&suite_free);
		check(ret == 1, "only one suite exist in ctest");
		free(ct->suites);
	}
	if (ct->path)
	{
		memset(ct->path, 0, strlen(ct->path));
		free(ct->path);
	}
	ct->path = NULL;
	ct->suites = NULL;
	memset(ct, 0, sizeof(ctest));
error:
	return;
}
