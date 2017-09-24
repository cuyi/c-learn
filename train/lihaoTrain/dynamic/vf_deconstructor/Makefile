
CC := g++  
CFLAGS := -g -Wall -std=c++11  
TARGET := main  
SRCS := $(wildcard *.cpp)  
OBJS := $(patsubst %cpp,%o,$(SRCS))

all:$(TARGET)  
%.o:%.cpp  
	$(CC) $(CFLAGS) -c $<
$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
clean:
	rm -rf $(TARGET) *.o *.cpp~

