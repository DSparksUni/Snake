IDIR = include
SDIR = src
ODIR = obj

vpath %.c $(SDIR)

CC = gcc
CFLAGS = -I $(IDIR) -Wall -Wno-missing-braces -Wconversion -pedantic -std=c11
TARGET = snake.exe

__OBJS = main.o console.o board.o
OBJS = $(patsubst %.o,$(ODIR)/%.o,$(__OBJS))

run: all
	./$(TARGET)

all: $(TARGET)
	echo Build Complete!

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

$(ODIR)/%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean
clean:
	rm $(TARGET) $(OBJS)
