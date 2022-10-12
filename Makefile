CC=gcc
TARGET=TINY_RENDERER

LIB_FOLDER=$(CURDIR)/libs
LDFLAGS=-g -lm -lSDL2

INCLUDES=$(foreach dir, $(wildcard $(LIB_FOLDER)/*), -I$(dir)/include/ -L$(dir)/bin/)
LDFLAGS+=$(INCLUDES)

CFLAGS=-DROOT=\"$(CURDIR)\" -DASSETS=\"$(CURDIR)/assets\"
CFLAGS+=$(LDFLAGS)

build: maths.o renderer.o camera.o vector.o model.o
	@echo "Running BUILD tasks..."
	@$(CC) $(CFLAGS) src/main.c out/*.o -o $(TARGET)

run: build
	@echo "Working directory: $(CURDIR)"
	@./$(TARGET)

# Libs

model.o: src/components/model.c src/components/model.h
	@echo "Compiling model.o"
	@$(CC) $(CFLAGS) -c src/components/model.c -o ./out/model.o

vector.o: src/components/vector.c src/components/vector.h
	@echo "Compiling vector.o"
	@$(CC) $(CFLAGS) -c src/components/vector.c -o ./out/vector.o

camera.o: src/components/camera.c src/components/camera.h
	@echo "Compiling camera.o"
	@$(CC) $(CFLAGS) -c src/components/camera.c -o ./out/camera.o

renderer.o: src/components/renderer.c src/components/renderer.h
	@echo "Compiling renderer.o"
	@$(CC) $(CFLAGS) -c src/components/renderer.c -o ./out/renderer.o

maths.o: src/components/maths.c src/components/maths.h
	@echo "Compiling maths.o"
	@$(CC) $(CFLAGS) -c src/components/maths.c -o ./out/maths.o

# Clean

.PHONY: clean
clean:
	@echo "Cleaning up..."
	@rm $(TARGET) ./out/*