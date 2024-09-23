#include "Geometricpp.hpp"
#include "Quadrilaterals.hpp"

int main(void)
{

    Geometricpp::Quadrilaterals::Square quadrado(10);

    std::cout << "Informações sobre o quadrado criado." << std::endl;
    std::cout << std::endl;

    std::cout << "Comprimento dos lados: " << quadrado.size() << std::endl;
    std::cout << "Área: " << quadrado.area() << std::endl;
    std::cout << "Perímetro: " << quadrado.perimeter() << std::endl;
    std::cout << "Diagonal: " << quadrado.diagonal() << std::endl;

    return 0;
}