CROSS=i686-linux-gnu-
AS=$(CROSS)as
CC=$(CROSS)gcc
LD=$(CROSS)ld

ASFLAGS := --32 -march=i386
CFLAGS := -m32 -march=i386 -ffreestanding -fno-stack-protector

SRCDIR := src

CSOURCE := $(wildcard $(SRCDIR)/*.c)
COBJ := $(patsubst %.c, %.o, $(notdir $(CSOURCE)))

ASMSOURCE := $(wildcard $(SRCDIR)/*.s)
ASMOBJ := $(patsubst %.s, %.o, $(notdir $(ASMSOURCE)))

OBJ := $(COBJ) $(ASMOBJ)

.PHONY: iso

iso: link
	cp kernel.bin iso/boot
	grub-mkrescue -o os.iso iso -d /usr/lib/grub/i386-pc

link: $(OBJ)
	$(LD) -melf_i386 -T src/linker.ld -nostdlib $(OBJ) -o kernel.bin

%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: $(SRCDIR)/%.s
	$(AS) $(ASFLAGS) $< -o $@

run: 
	qemu-system-i386 -cdrom os.iso
	
clean:
	rm *.o kernel.bin iso/boot/kernel.bin os.iso


