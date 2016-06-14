RISCV_NAME = riscv32-unknown-elf

ifeq ($(MULDIV),yes)
	CFLAGS += -march=RV32IMXcustom 
	RISCV_PATH=/opt/riscv32im/
endif
ifeq ($(MULDIV),no)
	CFLAGS += -march=RV32IXcustom  
	RISCV_PATH=/opt/riscv32i/
endif


