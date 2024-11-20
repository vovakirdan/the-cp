CC = gcc
CFLAGS = -Wall -std=c99 `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs`

SRCS = src/main.c src/map.c
OBJS = $(SRCS:.c=.o)

TARGET = platformer

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(OBJS) $(TARGET)
