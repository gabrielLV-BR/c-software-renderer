CC=gcc
TARGET=TINY_RENDERER

LIB_FOLDER=$(CURDIR)/libs
LDFLAGS=-g -lm -lSDL2

INCLUDES=$(foreach dir, $(wildcard $(LIB_FOLDER)/*), -I$(dir)/include/ -L$(dir)/bin/)
LDFLAGS+=$(INCLUDES)

CFLAGS=-DROOT=\"$(CURDIR)\" -DASSETS=\"$(CURDIR)/assets\"
CFLAGS+=$(LDFLAGS)

DEPENDENCIES=maths renderer camera vector model

# Rules

build: $(foreach dep, $(DEPENDENCIES), $(dep).o)
	@echo "Building project..."
	@$(CC) $(CFLAGS) src/main.c $^ -o $(TARGET)
	@echo "Done"

run: build
	@echo "Working directory: $(CURDIR)"
	@./$(TARGET)

# Libs

%.o: src/components/%.c src/components/%.h
	@echo "Compiling $*"
	@$(CC) $(CFLAGS) -c $<

# Clean

.PHONY: clean
clean:
	@echo "Cleaning up..."
	@rm -f $(TARGET) *.o