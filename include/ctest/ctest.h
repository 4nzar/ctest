#ifndef CTEST_H
# define CTEST_H

# define _POSIX_C_SOURCE 200809L

#include "internal/deque.h"
#include "suite/suite.h"
#include "test/expect.h"

#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>
#include <dirent.h>
#include <fnmatch.h>

# define USAGE_DESC_H "- Display available options."
# define USAGE_DESC_P "- Run test in specific folder."
# define USAGE_DESC_C "- Run test coverage."
# define USAGE_DESC_V "- "
# define USAGE_DESC_R "- Run specific test following a pattern."
# define USAGE_DESC_F "- "

# define ctest_start() ctest *ct = ctest_create();
# define ctest_end() if (ct) { ctest_free(ct); free(ct); }

typedef struct ctest
{
	char		*path;
	deque		*suites;
}				ctest;

ctest	*ctest_create(void);
int		ctest_push(ctest *ct, suite *s);
int		ctest_pop(ctest *ct);
void	ctest_free(ctest *ct);
void	usage(FILE *stream, char const *path, int exit_code);

#endif
