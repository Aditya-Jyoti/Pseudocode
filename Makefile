# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++11

# Directories
SRCDIR = src
BUILDDIR = build

# Source files
SOURCES = $(SRCDIR)/lexer/Lexer.cpp \
		  $(SRCDIR)/tokens/Tokens.cpp \
		  $(SRCDIR)/tests/Tests.cpp \
		  $(SRCDIR)/Main.cpp

# Object files
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)

# Executable name
EXEC = pseudo

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILDDIR)/*
	rm -f $(EXEC)

.PHONY: clean
