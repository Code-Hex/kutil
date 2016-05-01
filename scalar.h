#define let(_var, val) const __typeof__(val) _var = val
#define var(_var, val) __typeof__(val) _var = val