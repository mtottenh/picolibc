#ifndef __MEM_H__
#define __MEM_H__

void _memmove(void*, const void*, size_t);
void _memcpy(void*, const void*, size_t);
void _memset(void*, int, size_t);
void* _malloc(size_t);
void _free(void*);

#endif
