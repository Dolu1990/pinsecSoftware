PROJ_NAME=init
DEBUG=yes
BENCH=no
MULDIV=no


SRCS = 	$(wildcard src/*.c) \
				$(wildcard src/*.cpp)  \
				$(wildcard src/*.S)

INC += -I../../libs/test/
INC += -I../../libs/uart/

LDSCRIPT ?= ../../resources/linker.ld
include ../../resources/gcc.mk
include ../../resources/subproject.mk
