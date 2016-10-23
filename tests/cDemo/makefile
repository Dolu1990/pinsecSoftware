PROJ_NAME=cDemo
DEBUG=yes
BENCH=no
MULDIV=yes


SRCS = 	$(wildcard src/*.c) \
				$(wildcard src/*.cpp)  \
				$(wildcard src/*.S)

INC += -I../../libs/
INC += -I../../libs/test/
INC += -I../../libs/timer/
INC += -I../../libs/interrupt/

LDSCRIPT ?= ../../resources/linker.ld


include ../../resources/gcc.mk
include ../../resources/subproject.mk
