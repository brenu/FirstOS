#include "types.h"
#include "gdt.h"

void printf(char *message) {
    uint16_t* VideoMemory = (uint16_t*)0xb8000;

    for(int i = 0;message[i] != '\0';++i) {
        VideoMemory[i] = (VideoMemory[i] & 0xFF00) | message[i];
    }
}

typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors() {
    for(constructor* i = &start_ctors; i != &end_ctors; i++) {
        (*i)();
    }
}

extern  "C" void kernel(void *multiboot_structure, uint32_t magicnumber) {
    printf("Hello World, First OS!!!");

    GlobalDescriptorTable gdt;

    while(1);
}