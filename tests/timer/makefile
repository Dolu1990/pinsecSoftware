PROJ_NAME=timer
DEBUG=no
BENCH=no
MULDIV=no


SRCS = 	$(wildcard src/*.c) \
				$(wildcard src/*.cpp)  \
				$(wildcard src/*.S)

INC += -I../../libs/
INC += -I../../libs/test/
INC += -I../../libs/timer/
INC += -I../../libs/interrupt/

LDSCRIPT = ../../resources/linker.ld


include ../../resources/gcc.mk
include ../../resources/subproject.mk


			