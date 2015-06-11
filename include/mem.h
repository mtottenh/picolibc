#ifndef __MEM_H__
#define __MEM_H__

#define NULL 0
#define REQ_MAGIC 0xdeadbeef

void _memmove(void*, const void*, size_t);
void _memcpy(void*, const void*, size_t);
void _memset(void*, int, size_t);
void* _malloc(size_t);
void _free(void*);

/* Maloc Metadata */

struct block_meta {
    size_t size;
    struct block_meta *next;
    int free;
    int magic; /* debug */
};
//void* global_base = NULL;
#define META_SIZE sizeof(struct block_meta)
#endif
