#include "test/test.h"

int	test_free(test *t)
{
	debug("----- %s", __FUNCTION__);
	if (!t)
		return (0);
	if (t->expression)
	{
		memset(t->expression, 0, strlen(t->expression));
		free(t->expression);
	}
	if (t->description)
	{
		memset(t->description, 0, strlen(t->description));
		free(t->description);
	}
	if (t->location)
	{
		memset(t->location, 0, strlen(t->location));
		free(t->location);
	}
	if (t->remarks)
	{
		memset(t->remarks, 0, strlen(t->remarks));
		free(t->remarks);
	}
	t->expression = NULL;
	t->description = NULL;
	t->location = NULL;
	t->remarks = NULL;
	t->pass = 0;
	t->line = 0;
	memset(t->id, 0, sizeof(t->id));
	memset(t, 0, sizeof(test));
	return (1);
}
