# Definições de compilador e flags
CXX = g++
CXXFLAGS = -I include -Wall -std=c++17 -fPIC

# Diretórios
SRCDIR = src
INCDIR = include
BUILDDIR = build
TESTDIR = tests
TARGET_STATIC = $(BUILDDIR)/libgeometricpp.a
TARGET_SHARED = $(BUILDDIR)/libgeometricpp.so
DOCDIR = doc

# Fontes e objetos
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SOURCES))

TEST_SOURCES = $(wildcard $(TESTDIR)/*.cpp)
TEST_OBJECTS = $(patsubst $(TESTDIR)/%.cpp, $(BUILDDIR)/%.o, $(TEST_SOURCES))

# Regra padrão: compilar a biblioteca (versão estática e dinâmica)
all: $(TARGET_STATIC) $(TARGET_SHARED)

# Compilar biblioteca estática (.a)
$(TARGET_STATIC): $(OBJECTS)
	@mkdir -p $(BUILDDIR)
	ar rcs $@ $^

# Compilar biblioteca dinâmica (.so)
$(TARGET_SHARED): $(OBJECTS)
	@mkdir -p $(BUILDDIR)
	$(CXX) -shared -o $@ $^

# Compilar arquivos .cpp em .o
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compilar testes
tests: $(TEST_OBJECTS) $(TARGET_SHARED)
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) $^ -o $(BUILDDIR)/test_program -L$(BUILDDIR) -lgeometricpp

$(BUILDDIR)/%.o: $(TESTDIR)/%.cpp
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rodar os testes
test: tests
	@ LD_LIBRARY_PATH=$(BUILDDIR) ./$(BUILDDIR)/test_program

# Limpeza dos arquivos compilados
clean:
	rm -rf $(BUILDDIR)

# Instalar a biblioteca e os headers no sistema
install: $(TARGET_STATIC) $(TARGET_SHARED)
	@ echo "Instalando a biblioteca e headers..."
	mkdir -p /usr/local/lib /usr/local/include/geometricpp
	cp $(TARGET_STATIC) /usr/local/lib/
	cp $(TARGET_SHARED) /usr/lib/
	cp $(INCDIR)/*.hpp /usr/local/include/geometricpp/

uninstall:
	@echo "Removendo a biblioteca e headers..."
	rm -f /usr/local/lib/libgeometricpp.a
	rm -f /usr/local/lib/libgeometricpp.so
	rm -rf /usr/local/include/geometricpp

# Doxygen para gerar a documentação
docs:
	@ echo "Gerando documentação com Doxygen"
	@ doxygen Doxyfile

# Limpar a documentação
clean-docs:
	@rm -rf $(DOCDIR)/*

# Limpeza completa do projeto
clean-all: clean clean-docs

# Phony targets
.PHONY: all clean tests test install docs clean-docs clean-all
