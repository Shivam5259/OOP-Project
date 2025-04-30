CXX = g++
CXXFLAGS = -std=c++11 -Wall

SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = my_program
OUT = my_program.exe

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXECUTABLE)

%.o: %.cpp
	$(CXX) -c $< -o $@

run: $(OUT)
	./$(OUT)
	del /Q $(OUT)

clean:
	del /Q $(OBJECTS) $(EXECUTABLE)
