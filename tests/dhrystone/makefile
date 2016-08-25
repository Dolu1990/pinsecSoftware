PROJ_NAME=dhrystone
DEBUG=no
BENCH=true
MULDIV=yes

CFLAGS += -g -std=gnu99 -ffast-math -fno-common -funsigned-char -fno-inline -fno-builtin-printf 
LDFLAGS += -lc

CFLAGS +=  -DPREALLOCATE=1 -DHOST_DEBUG=0 -DMSC_CLOCK 


SRCS = 	$(wildcard src/*.c) \
				$(wildcard src/*.cpp)  \
				$(wildcard src/*.S)

INC += -I../../libs/
INC += -I../../libs/test/
INC += -I../../libs/uart/
INC += -I../../libs/timer/

LDSCRIPT = ../../resources/linker.ld


include ../../resources/gcc.mk
include ../../resources/subproject.mk


			