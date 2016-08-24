PROJ_NAME=dhrystone
DEBUG=yes
BENCH=no
MULDIV=no

CFLAGS += -std=gnu99 -ffast-math -fno-common -funsigned-char -fno-inline -fno-builtin-printf 
LDFLAGS += -lc

CFLAGS +=  -DPREALLOCATE=1 -DHOST_DEBUG=0 -DHZ=100000000 -DMSC_CLOCK 


SRCS = 	src/crt.S \
      	src/main.cpp  \
      	src/system.c \
      	src/dhry_1.c \
      	src/dhry_2.c

INC += -I../../libs/test/
INC += -I../../libs/uart/

LDSCRIPT = ../../resources/linker.ld


include ../../resources/gcc.mk
include ../../resources/subproject.mk


			