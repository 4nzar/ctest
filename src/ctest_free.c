#include "ctest/ctest.h"

void	ctest_free(ctest *ct)
{
	debug("----- %s", __FUNCTION__);
	if (!ct)
		return ;
	if (ct->suites)
	{
		deque_clear(ct->suites, (void *)&suite_free);
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
}
