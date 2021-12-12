#include "suite/suite.h"

int	suite_push(suite *s, test *t)
{
	int	ret;
	
	debug("----- %s", __FUNCTION__);
	if (!s)
		return (0);
	ret = deque_push(s->cases, (void *)t);
	return (ret);
}
