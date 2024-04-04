#include "./include/setup.h"
#include "./include/external.h"

static gdt_t descriptors[6];
static gdt_ptr_t gdtp;
static tss_t tss;

void setup(){
    gdtp.limit = (sizeof(descriptors)) -1;
    gdtp.base = &descriptors;
    mkdescriptor(0,0,0,0,0); //null
    mkdescriptor(1,0,0xffffffff,0x9a,0xa); //kernel code
    mkdescriptor(2,0,0xffffffff,0x92,0xc); //kernel data
    mkdescriptor(3,0,0xffffffff,0xfa,0xa); //user code
    mkdescriptor(4,0,0xffffffff,0xf2,0xc); //user data
    mkdescriptor(5,&tss,sizeof(tss_t)-1,0x89,0);//tss



    xlgdt((void*)&gdtp);
}


void mkdescriptor(uint8_t where, uint32_t base, uint32_t limit, uint8_t acsess, uint8_t flags){
    descriptors[where].limit_l = (limit & 0xffff);
    descriptors[where].limit_h_flags = (limit >> 16) & 0x0f;

    descriptors[where].base_h = (base >> 24) & 0xff;
    descriptors[where].base_m = (base >> 16) & 0xff;
    descriptors[where].base_l = (base & 0xffff);

    descriptors[where].limit_h_flags |= (flags << 4) & 0xf0;

    descriptors[where].acsess = acsess;
}