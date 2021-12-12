#include "suite/suite.h"


int	suite_pop(suite *s)
{
	int	ret;
	
	debug("----- %s", __FUNCTION__);
	if (!s)
		return (0);
	ret = deque_pop(s->cases, (void *)&test_free);
	return (ret);
}
