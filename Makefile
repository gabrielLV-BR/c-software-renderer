CC=gcc
TARGET=main.out
LIB_FOLDER=$(CURDIR)/libs

LDFLAGS=-g -lm -lSDL2
INCLUDES=$(foreach dir, $(wildcard $(LIB_FOLDER)/*), -I$(dir)/include/ -L$(dir)/bin/)
LDFLAGS+=$(INCLUDES)

DEFINES=-D ROOT=\"$(CURDIR)\" -D ASSETS=\"$(CURDIR)/assets\"
LDFLAGS+=$(DEFINES)

all: $(TARGET)

$(TARGET):
	@echo "Running BUILD tasks..."
	@$(CC) $(LDFLAGS) src/*.c -o $(TARGET)

run: $(TARGET)
	@echo "Working directory: $(CURDIR)"
	@./$(TARGET)

.PHONY: clean
clean:
	@echo "Cleaning up..."
	@rm $(TARGET)