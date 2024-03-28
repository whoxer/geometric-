# Variáveis
CXX = g++
CXXFLAGS = -std=c++11 -Wall
SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin
TARGET = geo
SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# Regras
all: $(BINDIR)/$(TARGET)

$(BINDIR)/$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(INCDIR)/%.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Limpeza
clean:
	rm -f $(OBJDIR)/*.o $(BINDIR)/$(TARGET)
