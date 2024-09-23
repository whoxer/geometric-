# Definições de compilador e flags
CXX = g++
CXXFLAGS = -Iinclude -Wall -std=c++17

# Diretórios
SRCDIR = src
INCDIR = include
BUILDDIR = build
TESTDIR = tests
TARGET = $(BUILDDIR)/main_program
TEST_TARGET = $(BUILDDIR)/test_program

# Fontes e objetos
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SOURCES))

TEST_SOURCES = $(wildcard $(TESTDIR)/*.cpp)
TEST_OBJECTS = $(patsubst $(TESTDIR)/%.cpp, $(BUILDDIR)/%.o, $(TEST_SOURCES))

# Regra padrão: compilar o programa principal
all: $(TARGET)

# Compilação do programa principal
$(TARGET): $(OBJECTS)
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compilar arquivos .cpp em .o
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compilar testes
tests: $(TEST_OBJECTS) $(OBJECTS)
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) $^ -o $(TEST_TARGET)

$(BUILDDIR)/%.o: $(TESTDIR)/%.cpp
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rodar o programa principal
run: $(TARGET)
	@./$(TARGET)

# Rodar os testes
test: tests
	@./$(TEST_TARGET)

# Limpeza dos arquivos compilados
clean:
	rm -rf $(BUILDDIR)

# Phony targets
.PHONY: all clean tests test run
