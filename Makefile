CXX = g++
CXXFLAGS = -Wall -std=c++17
LDFLAGS =

SRC_DIR = src
BUILD_DIR = build

SRC_FILES = $(shell find $(SRC_DIR) -name '*.cpp')
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))
DEP_FILES = $(OBJ_FILES:.o=.d)

EXECUTABLE = pseudo

all: $(BUILD_DIR)/$(EXECUTABLE)

$(BUILD_DIR)/$(EXECUTABLE): $(OBJ_FILES)
	@mkdir -p $(@D)
	$(CXX) $(LDFLAGS) $^ -o $@

-include $(DEP_FILES)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

clean:
	rm -f $(OBJ_FILES) $(DEP_FILES)

run: all
	./$(BUILD_DIR)/$(EXECUTABLE)

.PHONY: all clean run
