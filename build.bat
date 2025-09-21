arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -ffreestanding -nostdlib -Wl,-T,link.ld -o hello.elf hello.c
arm-none-eabi-objcopy -O binary hello.elf hello.bin