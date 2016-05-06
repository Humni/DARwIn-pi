CC = g++

LDFLAGS= -lpthread -ldl
SOURCES=src/run_test.cpp

OBJS=$(SOURCES:.cpp=.o)

TARGET=run_test

CFLAGS=-fPIC -C -Wall -shared $(INCLUDE_DIRS)

INCLUDE_DIRS = -Isrc -lLinux/lib/darwin.a

all: $(SOURCES) $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@
	
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
