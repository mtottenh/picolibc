#include <types.h>
#include <mem.h>
#include <unistd.h>

void _memmove(void* dest, const void* src, size_t len) {
    void* tmp[len];
    for (int i = 0; i < len; i++) 
        ((char* )tmp)[i] = ((char *)src)[i];
    for (int i = 0; i < len; i++)
        ((char* )dest)[i] = ((char *)tmp)[i];
}

void _memcpy(void* dest, const void* src, size_t len) {
    for (int i =0; i < len; i++)
        ((char* )dest)[i] = ((char *)src)[i];
}

void _memset(void* buff, int value, size_t len) {
    for (int i = 0; i < len; i++)
        ((unsigned *)buff)[i] = (unsigned)value;
}

void* _malloc(size_t len) {
    void* p = sbrk(0);
    void* reserve = sbrk(len);
    reserve = reserve == (void*) -1 ? NULL : reserve;
    //assert?
    return reserve;
}

void _free(void* ptr) {
    return;
}
