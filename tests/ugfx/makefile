PROJ_NAME=ugfx
DEBUG=no
BENCH=no
MULDIV=yes


GFXLIB=ugfx_lib
include ugfx_lib/gfx.mk
include ugfx_lib/drivers/gdisp/framebuffer/driver.mk
INC =  -I./src/ $(GFXINC) -I$(GFXLIB) -Iugfx_lib/drivers/gdisp/framebuffer


SRCS = 	$(wildcard src/*.c) $(GFXSRC) \
				$(wildcard src/*.cpp)  \
				$(wildcard src/*.S)

INC += -I../../libs/test/
INC += -I../../libs/uart/
INC += -I../../libs/vga/
INC += -I../../libs/
INC += -I../../libs/timer/

CFLAGS += -g -ffast-math -fno-common -funsigned-char -fno-builtin-printf 
LDFLAGS += -lm

LDSCRIPT = ../../resources/linker.ld
include ../../resources/gcc.mk
include ../../resources/subproject.mk


			