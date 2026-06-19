.global _Reset
_Reset:
    ldr sp, =0x20000    /* Set Stack Pointer to a safe address in RAM */
    bl test       /* Jump directly to your C entry function */
    b .               /* Infinite loop backup if C code ever exits */
