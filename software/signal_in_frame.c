#include <stdio.h>
#include <stdint.h>

#define LITTLE_ENDIAN   12
#define BIG_ENDIAN      21

int main() {   
    /* signal settings */
    uint8_t signal_endianness   = BIG_ENDIAN;
    uint8_t signal_start_bit    = 48;
    uint8_t signal_bit_len      = 16;
    
    uint64_t signal = 0;
    
    uint8_t frame[] = {0xC0, 0x5D, 0xFA, 0xF0, 0x0F, 0xFF, 0x5D, 0xC0};
    uint8_t *ptFrame = frame;
    
    printf("frame pointer value: %p\r\n", ptFrame);

    uint64_t mask = 0;
    for (uint8_t i=0; i<signal_bit_len; i++) {
        mask += 1ULL << i;
    }
    
    if (signal_endianness == LITTLE_ENDIAN) {
        for(uint8_t i=0; i<sizeof(frame); i++) {
            signal += ((uint64_t)frame[i] << (i * 8));
        }
        
        printf("Signal so far: 0x%lX\r\n", signal);
        
        signal = signal >> signal_start_bit;
        
        // uint64_t mask = 0;
        // for(uint8_t i=0; i<(64-signal_bit_len); i++) {
        //     mask += (1ULL<<(63-i));
        // }
        
        printf("mask: 0x%lX\r\n", mask);
        
        signal &= mask;
        printf("signal: 0x%lX\r\n", signal);
        
    } else {
        for(uint8_t i=0; i<sizeof(frame); i++) {
            signal += ((uint64_t)frame[i] << (56 - (i * 8)));
        }
        
        printf("Signal so far: 0x%lX\r\n", signal);

        uint8_t signal_shift = 64 - (signal_start_bit + signal_bit_len);
        signal = signal >> signal_shift;

        // uint64_t mask = 0;
        // for(uint8_t i=0; i<(64-signal_bit_len); i++) {
        //     mask += (1ULL<<(63-i));
        // }

        printf("mask: 0x%lX\r\n", mask);

        signal &= mask;
        printf("signal: 0x%lX\r\n", signal);
    }
    return 0;
}