#ifndef _TEST_H_
# define _TEST_H_

# include <stdlib.h>
# include <string.h>
# include "internal/debug.h"

typedef struct test
{
	char		id[1024];
	char		*description;
	char		*expression;
	char		*location;
	int			line;
	int			pass;
	char		*remarks;
}				test;

test	*test_create(
		char const *fname,
		char const *expr,
		char const *desc,
		char const *remarks,
		int pass,
		int line,
		char *location
		);
int		test_free(test *t);

#endif
