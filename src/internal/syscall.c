#include "syscall_int.h"
/* TODO: Set errno on error */

long __syscall_ret(unsigned long r) {
        if (r >  -4096UL) {
                return -1;
        }
        return r;
}
