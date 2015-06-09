#include <io.h>
#include <stdarg.h>
int _printf(const char* fmt, ...) {
    
    va_list a_list;
    va_start( a_list, fmt);

/*  The non portable way...
    int* ap;
    ap = &fmt;
    ap++;*/
    return 0;
}

