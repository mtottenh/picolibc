#include <types.h>
#include <mem.h>
#include <syscall.h>
#include "syscall_int.h"
void* global_base = NULL;


//static unsigned long brk(void*);
static void* sbrk(size_t);

/*static unsigned long brk(void* end) {
    return -(syscall(SYS_brk, end) != (unsigned long long) end);
}*/
static void* sbrk(size_t len) {
    unsigned long cur = syscall(SYS_brk, 0);
    unsigned long res = syscall(SYS_brk, cur+len);
    if (len && res != cur+len)
        return (void*)-1;
    return (void*)cur;
}

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

void* _request_block(struct block_meta* last_block, size_t len) {
    struct block_meta* block;
    block = sbrk(0);
    void* request = sbrk(len + META_SIZE);

    if (request == (void*) -1)
        return NULL;
    if (last_block)
        last_block->next = block;
    block->size = len;
    block->next = NULL;
    block->free = 0;
    block->magic = REQ_MAGIC;
    return block;
}
/* attempts to find a free block of size 
 * modifies @last*/
void* _find_block(struct block_meta** last_block, size_t len) {
    struct block_meta* current = global_base;
    while(current && !(current->free && current->size >= len)) {
        *last_block = current;
        current = current->next;
    }
    return current;
}

void* _malloc(size_t len) {
    if (len <= 0)
        return NULL;

    struct block_meta *block;

    if (!global_base) {
    /* First call to malloc */
        block = _request_block(NULL, len);
        if (!block)
            return NULL;
        global_base = block;
    } else {
    /* We allready have some blocks allocated */
        struct block_meta* last = global_base;
        block = _find_block(&last, len);
        if (!block)
            block = _request_block(last, len);
        if (!block)
            return NULL;
    }
    return block+1;
/*    void* p = sbrk(0);
    void* reserve = sbrk(len);
    reserve = reserve == (void*) -1 ? NULL : reserve;
    //assert?
    return reserve;*/
}

void _free(void* ptr) {
    return;
}
