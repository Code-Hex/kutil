void debug_int(int a);
void debug_long(long a);
void debug_float(float a);
void debug_double(double a);
void debug_string(char *a);
void debug_const_string(const char *a);
void debug_other(void *a);
void debug_lint(unsigned long long int a);

#define printType(X) _Generic((X), \
	int : debug_int, \
	long : debug_long, \
	float : debug_float, \
	double : debug_double, \
	char *: debug_string, \
	unsigned long long int : debug_lint, \
	const char *: debug_const_string, \
	default : debug_other \
)(X)