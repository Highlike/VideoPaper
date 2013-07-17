CC = g++
CFLAGS = -c -Wall -Ofast
LDFLAGS = $(shell pkg-config --cflags --libs opencv)
SOURCES = main.cpp geometry.cpp shapes.cpp ui.cpp
OBJECTS = $(SOURCES: .cpp = .o)
EXECUTABLE = videopaper

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
