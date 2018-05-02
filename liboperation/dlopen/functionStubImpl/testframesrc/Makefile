CC     	 = g++
CXXFLAGS = -Wall -g -O0
TARGET	 = testframe

all:$(TARGET)

OBJS = testframe.o
SRCS = testframe.cpp

$(OBJS):$(SRCS)
	$(CC) $(CXXFLAGS) -c $^

$(TARGET):$(OBJS)
	$(CC) -rdynamic -o $(TARGET) $(OBJS) -ldl

clean:
	rm -f *.o $(TARGET)