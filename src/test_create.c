#include "test/test.h"

test	*test_create(
		char const *fname,
		char const *expr,
		char const *desc,
		char const *remarks,
		int pass,
		int line,
		char *location
		)
{
	test	*t;

	debug("----- %s", __FUNCTION__);
	if (!fname || !expr || !remarks || !desc || !location)
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
	t->remarks = strdup(remarks);
	memset(t->id, 0, sizeof(t->id));
	sprintf(t->id, "%s_%s_l%d", fname, desc, line);
	debug("[new test]:\nid -> %s\nexpression -> [%s]\ndescription -> %s\nremarks -> %s\npass -> %d\nline -> %d\nlocation -> %s", t->id, t->expression, t->description, t->remarks, t->pass, t->line, t->location);
	return (t);
}
