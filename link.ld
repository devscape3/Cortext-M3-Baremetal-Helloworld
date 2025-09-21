/* Very simple linker script for Cortex-M3 */
ENTRY(main)

SECTIONS
{
  . = 0x20000000; /* Start in SRAM for simplicity */

  .text : {
    *(.text*)
    *(.rodata*)
  }

  .data : {
    *(.data*)
  }

  .bss : {
    *(.bss*)
    *(COMMON)
  }
}
