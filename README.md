# Geometricpp

**Geometricpp** é uma biblioteca C++ que fornece classes e funções para manipulação e cálculo de propriedades geométricas de figuras planas, como quadriláteros, retângulos, losangos e outros objetos geométricos básicos. Ela foi projetada para ser fácil de integrar em projetos C++ e permite realizar cálculos geométricos de maneira eficiente.

## Instalação

Para instalar e utilizar a biblioteca **Geometricpp**, siga os passos abaixo.

### Pré-requisitos

- **GCC** (ou outro compilador C++) instalado em seu sistema.
- **Make**: Ferramenta de automação de compilação.

### Clonando o repositório

1. **Clone o repositório**:

```bash
   git clone https://github.com/whoxer/geometricpp.git
   cd geometricpp
```

2. **Compile com o Make e certifique-se que esteja em modo sudo**:

```bash
    sudo make install
```

### Pelo arquivo compactado

1. **Baixe a última versão na aba releases**
2. **Descompacte e rode o script**

```bash
    tar -xzf geometricpp-<version>.tar.gz
    cd geometricpp-<version>/
```

3. **Rode o script de instalação**

```bash
    chmod +x install.sh
    sudo ./install.sh
```

### Exemplo

1. **Calculando o quadrado da hipotenusa com o Geometricpp:**

```cpp
#include <geometricpp/Geometricpp.hpp>

using namespace Geometricpp;

int main(void)
{
    float_t x, y, z;

    std::cout << "Geometricpp v0.0.1.0" << std::endl;
    std::cout << std::endl;

    std::cout << "Insira o comprimento do primeiro cateto: ";
    std::cin >> x;

    std::cout << "Insira o comprimento do segundo cateto: ";
    std::cin >> y;

    z = pitagoras(x, y);

    std::cout << "Cateto x: " << x << std::endl;
    std::cout << "Cateto y: " << y << std::endl;
    std::cout << "Hipotenusa z: " << z << std::endl;

    return 0;
}
```

2. **Compile:**

```bash
    g++ pitagoras.cpp -o pitag -Wall -Werror -lgeometricpp
    ./pitag
```

3. A saída deve ser algo como:

```text
    Geomtricpp v0.0.1.0

    Insira o comprimento do primeiro cateto: 20
    Insira o comprimento do segundo cateto: 34
    Cateto x: 20
    Cateto y: 34
    Hipotenusa z: 39.4462

```
