#include "suite/suite.h"

int	suite_free(suite *s)
{
	int ret;

	debug("----- %s", __FUNCTION__);
	if (!s)
		return (0);
	if (s->cases)
	{
		ret = deque_clear(s->cases, (void *)&test_free);
		check(ret == 2, "only 2 assertions exist in this suite");
		free(s->cases);
	}
	if (s->name)
	{
		memset(s->name, 0, strlen(s->name));
		free(s->name);
	}
	s->name = NULL;
	s->cases = NULL;
	memset(s, 0, sizeof(suite));
	free(s);
	return (1);
error:
	return (0);
}
