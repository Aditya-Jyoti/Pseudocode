# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++17

# Directories
SRCDIR = src
BUILDDIR = build

# Source files
SOURCES = $(SRCDIR)/lexer/Lexer.cpp \
          $(SRCDIR)/tests/Tests.cpp \
          $(SRCDIR)/tokens/TokenType.cpp \
          $(SRCDIR)/Main.cpp

# Object files
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)

# Executable name
EXEC = pseudo

all: $(BUILDDIR) $(EXEC)

$(BUILDDIR):
	@mkdir -p $(BUILDDIR)/lexer
	@mkdir -p $(BUILDDIR)/tests
	@mkdir -p $(BUILDDIR)/tokens

$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILDDIR)/*
	rm -f $(EXEC)

test:
	make
	./pseudo test


.PHONY: clean

