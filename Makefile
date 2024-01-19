#Compiler
CXX := g++

# test

#Compiler flag
CXXFLAGS := -std=c++11 -Iinclude
CXXFLAGS := -Wall

# Source files
SOURCE := src/main.cpp
SOURCE += $(wildcard include/Core/*.h)
SOURCE += $(wildcard include/Lib/*.h)
SOURCE += $(wildcard include/Screens/*.h)
SOURCE += $(wildcard include/Screens/Client/*.h)
SOURCE += $(wildcard include/Screens/User/*.h)
SOURCE += $(wildcard include/Screens/Currensies/*.h)


# Object files
OBJECTS := $(patsubst %.cpp, %.o, $(SOURCE))
OBJECTS += $(patsubst %.h, %.o, $(SOURCE))
OBJECTS += $(patsubst %.txt, %.o, $(SOURCE))

# Executable name
EXECUTABLE := myprogram


# Build rule for the executable
$(EXECUTABLE): $(OBJECTS)
	@echo "1"
	$(CXX) $(CXXFLAGS) $^ -o $@


# Build rule for object files
%.o: %.cpp
	@echo "2"
	$(CXX) $(CXXFLAGS) -c $< -o $@


# Clean rule
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
