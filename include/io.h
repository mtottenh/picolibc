#ifndef __IO_H__
#define __IO_H__
#include <stdarg.h>
#include <types.h>

struct fmtstr_args {

};

typedef struct fmtstr_args fmtstr_args_t; 
int _printf (const char*, ...);
int _sprintf(char*, const char*, ...);
int _snprintf(char*, size_t, const char*, ...);
int _vprintf(const char*, va_list);
int _vsprintf(char*, const char*, va_list);
/* The one which does the work */
int _vsnprintf(char*, size_t, const char*, va_list);
#endif
