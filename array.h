#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define array_typeinit(T) \
struct {		\
	T *data;	\
	int count;	\
	int size;	\
}

typedef array_typeinit(void *) void_array;
typedef array_typeinit(char *) string_array;
typedef array_typeinit(int) int_array;
typedef array_typeinit(short int) sint_array;
typedef array_typeinit(unsigned short int) usint_array;
typedef array_typeinit(unsigned int) uint_array;
typedef array_typeinit(long int) lint_array;
typedef array_typeinit(unsigned long int) ulint_array;
typedef array_typeinit(long long int) llint_array;
typedef array_typeinit(unsigned long long int) ullint_array;
typedef array_typeinit(char) char_array;
typedef array_typeinit(float) float_array;
typedef array_typeinit(double) double_array;

#define new_array(...) \
		_new_array(__VA_ARGS__, NULL)

#define array_init(a)				\
({									\
	memset((a), 0, sizeof(*(a)));	\
	(a)->size = 1;					\
})

#define array_deinit(a) \
({						\
	free((a)->data);	\
	array_init(a);		\
})

#define unpack(a) \
	(void **)&(a)->data, &(a)->count, &(a)->size, sizeof(*(a)->data)

#define typecast(a) __typeof__(a)
#define count(a) (a)->count
#define first(a) (a)->data[0]
#define last(a) (a)->data[(a)->count - 1]

#define push(a, val)		\
	dynalloc(unpack(a)) ?	\
		((a)->data[(a)->count++] = (val)) : 0;

#define pop(a) (a)->data[--(a)->count]

#define each(a, var, iter) \
		for ((iter) = 0; ((var) = (a)->data[(iter)]) && (iter) < count(a); (iter)++)

#define foreach(a, var) \
		for (int _ = 0; ((var) = (a)->data[_]) && _ < count(a); _++)

/*
#define _new_array(array, ...)									\
({																\
	array_init((void_array *)array);							\
	int n = (sizeof((int []){__VA_ARGS__}) / sizeof(int));		\
	(array)->data = calloc(n, sizeof(typecast((array)->data))); \
	(array)->size = n << 1;										\
	(array)->count = n;											\
	(array)->data = {__VA_ARGS__};								\
})
*/

void _new_array(void *array, ...);
int dynalloc(void **data, int *count, int *size, int msize);
