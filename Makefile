CC=gcc
LDFLAGS=-lm -g
TARGET=main.out
WORKING_DIR:=$(CURDIR)
DEFINES=-D ROOT=\"$(WORKING_DIR)\" -D ASSETS=\"$(WORKING_DIR)/assets\"
LDFLAGS+=$(DEFINES)

build:
	$(CC) $(LDFLAGS) src/*.c -o $(TARGET)

run: build
	echo "Working directory: $(WORKING_DIR)"
	./$(TARGET)

.PHONY: clean
clean:
	rm $(TARGET)