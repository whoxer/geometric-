#include <Geometricpp.hpp>

using namespace Quadrilaterals;

int main (void) 
{
    Square quadrado(50);

    std::cout << "Geometricpp v0.0.1.0" << std::endl;
    std::cout << std::endl;

    std::cout << "Informações sobre o quadrado criado" << std::endl;
    std::cout << std::endl;

    std::cout << "Comprimento dos lados: " << quadrado.size() << std::endl;
    std::cout << "Área: " << quadrado.area() << std::endl;
    std::cout << "Perímetro: " << quadrado.perimeter() << std::endl;
    std::cout << "Diagonal: " << quadrado.diagonal() << std::endl;

    return 0;
}