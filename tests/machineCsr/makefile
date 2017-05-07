PROJ_NAME=machineCsr
DEBUG=no
BENCH=yes
MULDIV=yes

CFLAGS += -g -std=gnu99 -ffast-math -fno-common -funsigned-char -fno-builtin-printf 
LDFLAGS += -lc


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


			