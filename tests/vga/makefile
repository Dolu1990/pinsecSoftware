PROJ_NAME=vga
DEBUG=no
BENCH=no
MULDIV=no


SRCS = 	$(wildcard src/*.c) \
				$(wildcard src/*.cpp)  \
				$(wildcard src/*.S)

INC += -I../../libs/test/
INC += -I../../libs/uart/
INC += -I../../libs/vga/
INC += -I../../libs/

CFLAGS += -g

LDSCRIPT ?= ../../resources/linker.ld
include ../../resources/gcc.mk
include ../../resources/subproject.mk
