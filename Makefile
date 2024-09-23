CXX = g++
CXXFLAGS = -Wall -std=c++17

PARENT_DIR = pseudocode
BUILD_DIR = build

SOURCES = $(wildcard $(PARENT_DIR)/src/**/*.cpp)
OBJECTS = $(SOURCES:$(PARENT_DIR)/%.cpp=$(BUILD_DIR)/%.o)

EXEC = pseudo

all: $(BUILD_DIR) $(EXEC)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(PARENT_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)/*
	rm -f $(EXEC)

.PHONY: clean