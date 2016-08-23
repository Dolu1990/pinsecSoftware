PROJ_NAME=dhrystone
DEBUG=yes
BENCH=no
MULDIV=no

CFLAGS +=  -DPREALLOCATE=1 -DHOST_DEBUG=0 -DHZ=100000000 -DMSC_CLOCK 

SRCS = 	$(wildcard src/*.c) \
      	$(wildcard src/*.cpp)  \
      	$(wildcard src/*.S)

INC += -I../../libs/test/
INC += -I../../libs/uart/

LDSCRIPT = ../../resources/linker.ld

include ../../resources/gcc.mk
include ../../resources/subproject.mk


			