CC = g++

LDFLAGS= -lpthread -ldl
SOURCES=Framework/src/CM730.cpp Linux/build/LinuxCM730.cpp Framework/src/MX28.cpp src/run_test.cpp

OBJS=$(SOURCES:.cpp=.o)

TARGET=run_test

CFLAGS=-fPIC -C -Wall -shared $(INCLUDE_DIRS)

INCLUDE_DIRS = -Isrc -IFramework/include -ILinux/include

all: $(SOURCES) $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@
	
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
