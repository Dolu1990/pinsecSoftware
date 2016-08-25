/*======================================================================*/
/* Proxy kernel linker script                                           */
/*======================================================================*/
/* This is the linker script used when building the proxy kernel. */

/*----------------------------------------------------------------------*/
/* Setup                                                                */
/*----------------------------------------------------------------------*/

/* The OUTPUT_ARCH command specifies the machine architecture where the
   argument is one of the names used in the BFD library. More
   specifically one of the entires in bfd/cpu-mips.c */

OUTPUT_ARCH( "riscv" )

/*----------------------------------------------------------------------*/
/* Sections                                                             */
/*----------------------------------------------------------------------*/

MEMORY {
  rom (RX) : ORIGIN = 0x00000000, LENGTH = 96K
  ram (W!RX) : ORIGIN = 0x40000000, LENGTH = 64M
  /*ram (W!RX) : ORIGIN = 0x04000000, LENGTH = 32K*/
}
_stack_size = 4k;
_heap_size = 8k;

SECTIONS /*TODO don't initialize useless things,  restore literal loading that use 2 instruction in place of rom word */
{


   /* text: test code section */
   . = 0x000;
   .text :
   {
    . = ALIGN(4);
    _text = .;
    PROVIDE(stext = .);
    KEEP(*(.isr_vector))
    *crt.o(.text)
    *(.text .text.*)            
    *(.rodata .rodata.*)        
    *(.srodata .srodata.*)         
    *(.eh_frame)       
    *(.gnu.linkonce.t.*)
    *(.glue_7)
    *(.glue_7t)
    *(.gcc_except_table)
    *(.gnu.linkonce.r.*)
    . = ALIGN(4);
    _etext = .;
    _sidata = _etext;
    PROVIDE(etext = .);   
 		_fini = . ;
		*(.fini)  
   } > rom

  /* .ctors => Contains a list of global constructor pointers */
  .ctors ALIGN(4) : {
    _ctors_load_start = .;
    _ctors_start = .;
    KEEP(*(.init_array*))
    KEEP (*(SORT(.ctors.*)))
    KEEP (*(.ctors))
  } > rom
  _ctors_end = _ctors_start + SIZEOF(.ctors);
  
  _copy_section = _ctors_start + SIZEOF(.ctors);
   .data : AT (_copy_section) /* ADDR(.text) + SIZEOF ( .text )     AT (_etext) */
   {
      . = ALIGN(4);
      _sdata = .;
      *(.ramfunc .ramfunc.* .fastrun .fastrun.*)
      *(.data .data.*)
      *(.sdata .sdata.*)
      *(.gnu.linkonce.d.*)
      . = ALIGN(4);
      _edata = .;
   } > ram


  .bss (NOLOAD) : {
  . = ALIGN(4);
      /* This is used by the startup in order to initialize the .bss secion */
      _bss_start = .;
      *(.sbss .sbss.*)
      *(.bss .bss.*)
      *(.gnu.linkonce.b.*)
      *(COMMON)
      . = ALIGN(4);        
      _bss_end = .;
  } > ram


	._user_heap (NOLOAD):
	{
		. = ALIGN(8);
		PROVIDE ( end = . );
		PROVIDE ( _end = . );
		PROVIDE ( _heap_start = .);
		. = . + _heap_size;
		. = ALIGN(8);
		PROVIDE ( _heap_end = .);
	} > ram
	
	._stack (NOLOAD):
	{
		. = ALIGN(4);
		PROVIDE (_stack_end = .);
		. = . + _stack_size;
		. = ALIGN(4);
		PROVIDE (_stack_start = .);
	} > ram


}
