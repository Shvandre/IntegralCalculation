CFLAGS ?= -O0 -g
CFLAGS += -std=gnu99
CFLAGS += -Wall -Werror -Wformat-security -Wignored-qualifiers -Winit-self \
	-Wswitch-default -Wpointer-arith -Wtype-limits -Wempty-body \
	-Wstrict-prototypes -Wold-style-declaration -Wold-style-definition \
	-Wmissing-parameter-type -Wmissing-field-initializers -Wnested-externs \
	-Wstack-usage=4096 -Wfloat-equal -Wabsolute-value
CFLAGS += -fsanitize=undefined -fsanitize-undefined-trap-on-error
CC += -m32 -no-pie -fno-pie
LDLIBS = -lm


OBJS = BuildDir/main.o BuildDir/Tools.o BuildDir/ArgParse.o BuildDir/MathFunctions.o #BuildDir/MathFunctionsC.o
TARGET = integral

all: $(OBJS)
	mkdir -p BuildDir
	gcc -m32 -o $(TARGET) $(OBJS) $(LDLIBS)

# Object files from .asm
BuildDir/%.o: Source/%.asm
	nasm -g -f elf32 -o $@ $<
#Link all object files with gcc
BuildDir/%.o: Source/%.c
	gcc -m32 -c $(CFLAGS) -o $@ $<

.PHONY: clean
clean:
	rm -f BuildDir/* $(TARGET)