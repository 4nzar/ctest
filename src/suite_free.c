#include "suite/suite.h"

int	suite_free(suite *s)
{
	debug("----- %s", __FUNCTION__);
	if (!s)
		return (0);
	if (s->cases)
	{
		deque_clear(s->cases, (void *)&test_free);
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
	return (1);
}
