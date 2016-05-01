#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>

#define let(_var, val) const __typeof__(val) _var = val
#define istype(value) __typeof__(value)

#define new_array(...) \
	init_array(NULL, __VA_ARGS__, NULL)

typedef struct _array
{
	int index;
	void *value;
	struct _array *ptr;
} array;

int isnum(void *s)
{
	return isdigit((int)s);
}

void init_array(const void *null, ...) {
	va_list args;
	void *str;
	int i;

	va_start(args, null);
	for (i = 0; (str = va_arg(args, void *)) != NULL; i++)
	{
		printf("%s\n", istype(str));
	}

	va_end(args);
}

int main(int argc, char const *argv[])
{
	new_array("Hello", ", ", 10, "Worldwww", "!!", "se", "deed");
	return 0;
}