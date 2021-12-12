#include "test/test.h"

test	*test_create(
		char const *fname,
		char const *expr,
		char const *desc,
		int pass,
		int line,
		char *location
		)
{
	test	*t;

	debug("----- %s", __FUNCTION__);
	if (!fname || !expr || !desc || !location)
		return (NULL);
	t = (test *)malloc(sizeof(test));
	if (!t)
		return (NULL);
	memset(t, 0, sizeof(test));
	t->pass = pass;
	t->line = line;
	t->expression = strdup(expr);
	t->description = strdup(desc);
	t->location = strdup(location);
	memset(t->id, 0, sizeof(t->id));
	sprintf(t->id, "%s_%s_l%d", fname, desc, line);
	return (t);
}
