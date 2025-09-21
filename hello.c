#include <stdint.h>

#define UART0_BASE   0x40000000

#define UART0_DR     (*(volatile uint32_t *)(UART0_BASE + 0x00))
#define UART0_FR     (*(volatile uint32_t *)(UART0_BASE + 0x18))
#define UART0_CR     (*(volatile uint32_t *)(UART0_BASE + 0x30))

void uart_init(void) {
    // Enable UART, TX, and RX
    UART0_CR = (1 << 0)   // UARTEN
             | (1 << 8)   // TXE
             | (1 << 9);  // RXE
}

void uart_putc(char c) {
    // Wait until transmit FIFO not full
    while (UART0_FR & (1 << 5)); // TXFF bit
    UART0_DR = c;
}

void uart_print(const char *s) {
    while (*s) {
        if (*s == '\n') uart_putc('\r');
        uart_putc(*s++);
    }
}

void main(void) {
    uart_init();
    uart_print("Hello, World from Cortex-M3 in Renode!\n");
    while (1) { }
}

/* Reset stuff unchanged */
void Reset_Handler(void) { main(); }
void Default_Handler(void) { while(1) {} }

__attribute__((section(".isr_vector")))
uint32_t vector_table[] = {
    0x20002000,             // Initial stack pointer
    (uint32_t)Reset_Handler // Reset handler
};
