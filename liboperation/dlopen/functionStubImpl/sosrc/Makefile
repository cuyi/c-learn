CC     	 = gcc
CFLAGS   = -Wall -g -O0 -fPIC
CXXFLAGS =
TARGET   = a.so
INCLUDE  = ./
LIBPATH  = ./libs/

all:$(TARGET)

OBJS = a.o
SRCS = a.c

$(OBJS):$(SRCS)
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $^

$(TARGET):$(OBJS)
	$(CC) -shared -fPIC -o $(TARGET) $(OBJS)
	rm -rf $(LIBPATH)
	mkdir $(LIBPATH)
	mv $(TARGET) $(LIBPATH)

clean:
	rm -f *.o
	rm -rf $(LIBPATH)