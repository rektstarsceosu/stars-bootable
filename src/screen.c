#include "include/screen.h"

void scroll(void){
    /*TODO*/


    return;
}

void putc(vidmem_t c){
    if(c.c == '\n'){
        cursor.y++;
        return;
    }
    if(c.c == '\r'){
        cursor.x=0;
        return;
    }
    if(cursor.x==MAX_X){
        cursor.x=0;
        cursor.y++;
    }
    if(cursor.y>MAX_Y){
        cursor.y=MAX_Y;
        scroll();
    }
    vidmem[cursor.y*(MAX_X+1)+cursor.x] = c;
    cursor.x++;
    return;   
}

uint32_t puts(char* s,uint8_t fg,uint8_t bg){
    uint32_t i;
    for(i=0; s[i]; i++){
        putc(mkchar(s[i],fg,bg));
    }
    return i;
}

vidmem_t mkchar(char c,uint8_t fg,uint8_t bg){
    vidmem_t character;
    character.color = fg | bg << 4;
    character.c = c;
    return (vidmem_t) character;
}