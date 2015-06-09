#include <types.h>
#include <string.h>

size_t _strlen(char* buff) {
        size_t size = 0;
        for(; buff[size] != 0; size++) {} 
        return --size;
}

char* reverse(char* buff) {
        size_t size = _strlen(buff);
        for(int i = 0; i < size - i; i++) {
            buff[i] = buff[size - i] ^ buff[i];
            buff[size - i] = buff[i] ^ buff[size - i];
            buff[i] = buff[i] ^ buff[size - i];
        }
        return buff;
}


