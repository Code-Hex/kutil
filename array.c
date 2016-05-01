#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include "array.h"

int dynalloc(void **data, int *count, int *size, int msize) {
	if (*count + 1 >= *size)
	{
		*size <<= 1; /* 1, 2, 4, 8, 16, ... */
		void *ptr = realloc(*data, *size * msize);
		if (ptr == NULL) return 0;
		*data = ptr;
	}
	return 1;
}

void _new_array(void *array, ...)
{
	va_list args;
	void *arg;
	array_init((void_array *)array);
	va_start(args, array);
	while ((arg = va_arg(args, void *)) != NULL)
	{
		//printf("%s\n", arg);
		push((void_array *)array, arg);
	}

	va_end(args);
}

int main(int argc, char const *argv[])
{
	string_array ary;
	new_array(&ary, "Hello", ", ", "Worldwww", "!!", "se", "deed");
	return 0;
}