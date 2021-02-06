#include <stdio.h>
#include <stdint.h>

#define LITTLE_ENDIAN   0
#define BIG_ENDIAN      1

int main() {   
    /* signal settings */
    uint8_t signal_endianness   = BIG_ENDIAN;
    uint8_t signal_start_bit    = 28;
    uint8_t signal_bit_len      = 16;
    
    uint64_t signal = 0;
    
    uint8_t frame[] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF};
    uint8_t *ptFrame = frame;
    
    printf("frame pointer value: %p\r\n", ptFrame);
    
    uint8_t signal_byte = signal_start_bit / 8;
    uint8_t signal_remaining_bits = signal_start_bit % 8;
    
    printf("Signal Start: %dbytes, %dbits\r\n", signal_byte, signal_remaining_bits);
    
    uint8_t len_bytes = signal_bit_len / 8;
    uint8_t len_remaining_bits = signal_bit_len % 8;
    printf("Signal Len: %dbytes, %dbits\r\n", len_bytes, len_remaining_bits);
    
    if (signal_endianness == LITTLE_ENDIAN) {
        for(uint8_t i=0; i<sizeof(frame); i++) {
            signal += ((uint64_t)frame[i] << (i * 8));
        }
        
        printf("Signal so far: 0x%lX\r\n", signal);
        
        signal = signal >> signal_start_bit;
        
        uint64_t mask = 0;
        for(uint8_t i=0; i<(64-signal_bit_len); i++) {
            mask += (1ULL<<(63-i));
        }
        
        printf("mask: 0x%lX\r\n", mask);
        
        signal &= ~mask;
        printf("signal: 0x%lX\r\n", signal);
        
    } else {
        for(uint8_t i=0; i<sizeof(frame); i++) {
            signal += ((uint64_t)frame[i] << (56 - (i * 8)));
        }
        
        printf("Signal so far: 0x%lX\r\n", signal);

        signal = signal >> signal_start_bit;

        uint64_t mask = 0;
        for(uint8_t i=0; i<(64-signal_bit_len); i++) {
            mask += (1ULL<<(63-i));
        }

        signal &= ~mask;
        printf("signal: 0x%lX\r\n", signal);
    }
    return 0;
}