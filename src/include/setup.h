#include <stdint.h>

typedef struct {
   uint16_t offset_l;        
   uint16_t selector;       
   uint8_t  zero;            // unused, set to 0
   uint8_t  type_attributes; 
   uint16_t offset_h;       
} idt_t;

typedef struct {
    uint32_t link;
    uint32_t esp0;
    uint32_t ss0;
    uint32_t reserved0;
    uint32_t esp1;
    uint32_t ss1;
    uint32_t reserved1;
    uint32_t esp2;
    uint32_t ss2;
    uint32_t reserved2;
    uint32_t cr3;
    uint32_t eip;
    uint32_t eflags;
    uint32_t eax;
    uint32_t ecx;
    uint32_t edx;
    uint32_t ebx;
    uint32_t esp;
    uint32_t ebp;
    uint32_t esi;
    uint32_t edi;
    uint32_t es;
    uint32_t cs;
    uint32_t ss;
    uint32_t ds;
    uint32_t fs;
    uint32_t gs;
    uint32_t reserved3;
    uint32_t iopb;
    uint32_t ssp;
} tss_t;


typedef struct{
    uint16_t limit_l;
    uint16_t base_l;
    uint8_t base_m;
    uint8_t acsess;
    uint8_t limit_h_flags;
    uint8_t base_h;
}__attribute__((packed)) gdt_t;

typedef struct{
    uint16_t limit;
    uint32_t base;
}__attribute__((packed)) gdt_ptr_t;

void setup();
void mkdescriptor(uint8_t where,uint32_t base,uint32_t limit,uint8_t acsess,uint8_t flags);