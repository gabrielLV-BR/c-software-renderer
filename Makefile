CC=gcc
LDFLAGS=-lm -g
TARGET=main.out
DEFINES= -D ASSETS=\"$(shell pwd)/assets/\" -D ROOT=\"$(shell pwd)\"
LDFLAGS+=$(DEFINES)
build:
	echo "Assets: $(DEFINES)" 
	$(CC) $(LDFLAGS) src/*.c -o $(TARGET)

run: build
	clear
	./$(TARGET)

.PHONY: clean
clean:
	rm $(TARGET)