#include <io.h>
#include <types.h>
#include <stdarg.h>
#include <mem.h>
static int _parse_fmtstr_args(const char*, fmtstr_args_t*, va_list);
static int _vsnprintf_real(char*, size_t, const char*, fmtstr_args_t*);

static int 
_vsnprintf_real(char* s, size_t n, const char* fmt, fmtstr_args_t* arg) {

}


static int
_parse_fmtstr_args(const char* fmt, fmtstr_args_t* args, va_list vargl) {
    return 0;
}

int _printf(const char* fmt, ...) {
    
    va_list a_list;
    va_start( a_list, fmt);
    char *buff = 0; /* TODO: How do we determine this */
    size_t len = 0;    
    fmtstr_args_t args;
    len = _parse_fmtstr_args(fmt, &args, a_list);
    buff = _malloc(len+1);
    _vsnprintf_real(buff,len,fmt,&args);
    return 0;
}

int _sprintf(char* s, const char* fmt, ...) {

}

int _snprintf(char *s, size_t n, const char* fmt, ...) {

}

int _vprintf(const char* fmt, va_list vargl) {

}

int _vsprintf(char* s, const char* fmt, va_list vargl) {

}

int _vsnprintf(char* s, size_t n, const char* fmt, va_list vargl) {

}

