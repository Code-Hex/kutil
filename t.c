#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include "debug.h"

#define let(_var, val) const __typeof__ (val) _var = val
#define var(_var, val) __typeof__ (val) _var = val

typedef struct _Array
{
	int index;
	void *value;
	struct _Array *ptr;
} Array;

int main(int argc, char const *argv[])
{
	unsigned long long int y = 10;
	printType(y);
	return 0;
}