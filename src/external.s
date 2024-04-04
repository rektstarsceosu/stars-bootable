.globl outpb
.globl xlgdt
.section .text

xlgdt:
   mov 4(%esp),%eax
   lgdt (%eax)

   mov $0x10, %eax
   mov %ax, %ds
   mov %ax, %es
   mov %ax, %fs
   mov %ax, %gs
   mov %ax, %ss
   jmp  $0x08,$.load
    .load:
        ret

outpb:
    push %ax
    push %dx
    push %ebp
    mov %esp,%ebp
    movw 8(%ebp), %dx
    movb 12(%ebp), %al
    outb %al, %dx
    pop %ebp
    pop %dx
    pop %ax
    ret
