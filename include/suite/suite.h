#ifndef _SUITE_H_
# define _SUITE_H_

# include "test/test.h"
# include "internal/deque.h"
# include "internal/debug.h"

typedef struct suite
{
	char		*name;
	deque		*cases;
	size_t		nb_success;
	size_t		nb_warning;
	size_t		timeout;
}				suite;

suite	*suite_create(char const *name);
int		suite_push(suite *s, test *t);
int		suite_pop(suite *s);
int		suite_free(suite *s);

#endif
