# Compiler settings
CXX = g++
CXXFLAGS = -Wall -std=c++17 -I$(PARENT_DIR)/include

# Directory structure
PARENT_DIR = pseudocode
BUILD_DIR = build

# Source files and object files
SOURCES = $(wildcard $(PARENT_DIR)/src/*.cpp)
OBJECTS = $(SOURCES:$(PARENT_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Executable name
EXEC = pseudo

# Phony targets
.PHONY: all clean

# Default target
all: $(BUILD_DIR) $(EXEC)

# Create build directory
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)/src

# Link the executable
$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile source files into object files
$(BUILD_DIR)/%.o: $(PARENT_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)
	rm -f $(EXEC)

# Debugging information
print-%  : ; @echo $* = $($*)