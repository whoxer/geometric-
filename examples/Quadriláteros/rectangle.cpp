#include <Geometricpp.hpp>

using namespace Geometricpp;
using namespace Quadrilaterals;

int main(void) 
{
    Rectangle retangulo(100, 50);

    std::cout << "Geometricpp v0.0.1.0" << std::endl;
    std::cout << std::endl;

    std::cout << "Informações sobre o retângulo criado" << std::endl;
    std::cout << std::endl;

    std::cout << "Área: " << retangulo.area() << std::endl;
    std::cout << "Perímetro: " << retangulo.perimeter() << std::endl;
    std::cout << "Diagonal: " << retangulo.diagonal() << std::endl;
    std::cout << "Comprimento dos lados (h, w): " << retangulo.size() << std::endl;
}