#include <stdio.h>

void debug_int(int a) {
	printf("int:\t%d\n", a);
}
void debug_long(long a) {
	printf("long:\t%ld\n", a);
}
void debug_float(float a) {
	printf("float:\t%f\n", a);
}
void debug_double(double a) {
	printf("double:\t%f\n", a);
}
void debug_string(char *a) {
	printf("char *:\t%s\n", a);
}
void debug_const_string(const char *a) {
	printf("const char *:\t%s\n", a);
}
void debug_other(void *a) {
	printf("unknown");
}
