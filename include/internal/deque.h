#ifndef _DEQUE_H_
# define _DEQUE_H_

# include <stdlib.h>
# include <string.h>

# include "internal/debug.h"

# define DEQUE_SUCCESS 0
# define DEQUE_ERROR_DEQUE_NULL -1
# define DEQUE_ERROR_DEQUE_EMPTY -2
# define DEQUE_ERROR_MEMORY_ALLOCATION -3
# define DEQUE_ERROR_FAILURE -4
# define DEQUE_ERROR_NODE_NULL -5

typedef struct deque_node
{
	void				*data;
	struct deque_node	*next;
	struct deque_node	*prev;
}						deque_node;

typedef struct deque
{
	deque_node			*head;
	size_t				len;
}						deque;

deque_node	*deque_new_node(void *data);
deque		*deque_new(void);
int			deque_push(deque *d, void *data);
int			deque_unshift(deque *d, void *data);
int			deque_pop(deque *d, int (*fn)(void *));
int			deque_shift(deque *d);
int			deque_isempty(deque const *d);
size_t		deque_size(deque const *d);
int			deque_map(deque *d, deque_node *(*cb)(deque_node *node));
int			deque_mapi(deque *d, deque_node *(*cb)(unsigned int, deque_node *node));
deque_node	*deque_peek(deque const *d);
size_t			deque_clear(deque *d, int (*fn)(void *));
char			*deque_tostring(deque const *d);
char			*deque_node_tostring(deque_node const *node);

#endif
