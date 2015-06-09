#ifndef _GENERIC_TYPES_
#define _GENERIC_TYPES_


typedef signed char         int8_t;
typedef unsigned char       uint8_t;

typedef signed short        int16_t;
typedef unsigned short      uint16_t;

typedef signed int          int32_t;
typedef unsigned int        uint32_t;

typedef signed long long    int64_t;
typedef unsigned long long  uint64_t;

/*  */
#if __SIZEOF_POINTER__ == 4
typedef unsigned int size_t;
#elif __SIZEOF_POINTER__ == 8
typedef unsigned long size_t;
#else
#error "unsupported architecture"
#endif

#endif
