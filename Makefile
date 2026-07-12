# Compiler
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude

# Libraries
LIBS := -lraylib -llunasvg

# Directories
SRC_DIR := src
BUILD_DIR := build

# Executable
TARGET := $(BUILD_DIR)/chess

# Find all .cpp files in src/
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)

# Convert src/foo.cpp -> build/foo.o
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

# Default target
all: $(TARGET)

# Create build directory if needed
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compile each .cpp into a .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link executable
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LIBS)

# Run program
run: $(TARGET)
	./$(TARGET)

# Clean build files
clean:
	rm -rf $(BUILD_DIR)

# Rebuild everything
rebuild: clean all

.PHONY: all run clean rebuild