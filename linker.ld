ENTRY(_Reset)
SECTIONS
{
 . = 0x10000; 
 .text : { 
    startup.o(.text)  /* FORCE the assembly startup code to be at 0x10000 */
    *(.text) 
 }
 .data : { *(.data) }
 .bss :  { *(.bss)  }
}
