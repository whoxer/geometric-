# Variáveis
CXX = g++
CXXFLAGS = -std=c++11 -Wall
SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin
TESTDIR = tests
TARGET = geo
TEST_TARGET = square_test
EXAMPLE_TARGET = exemplos
SOURCES := $(wildcard $(SRCDIR)/*.cpp)
TEST_SOURCES := $(wildcard $(TESTDIR)/*.cpp)
OBJECTS := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
TEST_OBJECTS := $(TEST_SOURCES:$(TESTDIR)/%.cpp=$(OBJDIR)/%.o)

# Regras
all: $(BINDIR)/$(TARGET)

$(BINDIR)/$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(INCDIR)/%.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BINDIR)/$(EXAMPLE_TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(SRCDIR)/exemplo.cpp

$(BINDIR)/$(TEST_TARGET): $(OBJECTS) $(TEST_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(TESTDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Limpeza
clean:
	rm -f $(OBJDIR)/*.o $(BINDIR)/$(TARGET) $(BINDIR)/$(EXAMPLE_TARGET) $(BINDIR)/$(TEST_TARGET)
