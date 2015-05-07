CC=g++
CFLAGS=-c
LDFLAGS=
SOURCES=STTModel.cpp ExpressionParser/ExpressionClasses.cpp ExpressionParser/Parser.cpp
CLI=STTCommandLineInterface.cpp
MODELOBJECTS=$(SOURCES:.cpp=.o)
CLOBJ=$(CLI:.cpp=.o)
EXECUTABLE=stt-cli.exe

all: $(SOURCES) $(EXECUTABLE)

run: all
	./$(EXECUTABLE)
    
$(EXECUTABLE): $(MODELOBJECTS) $(CLOBJ)
	$(CC) $(LDFLAGS) $(MODELOBJECTS) $(CLOBJ) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
