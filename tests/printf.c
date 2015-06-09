#include <stdio.h>
#include <string.h>
#include <mem.h>
#include <types.h>
#define TPM_DIGEST_SIZE 20
#define BUFSIZE sizeof(long long)*2 + 2

static char sbuff[TPM_DIGEST_SIZE+1] = {   0xf3, 0x63, 0x74, 0x4e, 0x28, 0x9d,
                                           0xfa, 0x01, 0x5a, 0xcf, 0x5f, 0x27,
                                           0x4d, 0xe4, 0x15, 0x48, 0x8e, 0x80,
                                           0x1d, 0x10, 0x00 };

void print_as_bytes(const char* const buff) {
    for (int i = 0; i < TPM_DIGEST_SIZE; i++) {
        printf("%hhX ",buff[i]);
    }
    printf("\n");
}

static inline char* lltoa_shr(unsigned long long d) {
    char* buff = _malloc(BUFSIZE+1);
    buff[BUFSIZE] = 0;
    buff[0] = '0';
    buff[1] = 'x';
      
    if ((long long)d < 0)
        d = -d;

    for(char* p= &buff[2]; d != 0; d>>=4) {
        unsigned int n = (unsigned)d & 0xf;
        *p++ = n > 9 ? (n + 'a' - 10) : n + '0';
    }
    reverse(&buff[2]);
    return buff;
}

static inline char* lltoa_div(unsigned long long d) {
    char* buff = _malloc(BUFSIZE+1);
    buff[BUFSIZE] = 0;
    buff[0] = '0';
    buff[1] = 'x';

    if ((long long)d < 0)
        d = -d;

    for (char* p = &buff[2]; d != 0; d /= 16) {
        unsigned int n = (unsigned) d & 0xf;
        *p++ = n > 9 ? (n + 'a' - 10) : n + '0';
    }
    reverse(&buff[2]);
    return buff;
}

int main() {
    printf("sbuff as a string: %s\n", sbuff);
    printf("sbuff as bytes: ");
    print_as_bytes(sbuff);
    printf("0xa SHR: %s\n", lltoa_shr(0xa));
    printf("0xa DIV: %s\n", lltoa_div(0xa));
    return 0;
}
