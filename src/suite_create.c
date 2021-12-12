#include "suite/suite.h"

suite	*suite_create(char const *name)
{
	suite	*s;

	debug("----- %s", __FUNCTION__);
	if (!name)
		return (NULL);
	s = (suite *)malloc(sizeof(suite));
	if (!s)
		return (NULL);
	memset(s, 0, sizeof(suite));
	s->name = strdup(name);
	s->cases = deque_new();
	s->nb_success = 0;
	s->nb_warning = 0;
	return (s);
}
