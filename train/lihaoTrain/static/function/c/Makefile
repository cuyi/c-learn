
CC := gcc  
CFLAGS := -g -Wall  
TARGET := main  
SRCS := $(wildcard *.c)  
OBJS := $(patsubst %c,%o,$(SRCS))

all:$(TARGET)  
%.o:%.c
	$(CC) $(CFLAGS) -c $<
$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
clean:
	rm -rf $(TARGET) *.o

