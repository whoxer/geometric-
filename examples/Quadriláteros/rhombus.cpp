#include <geometricpp/Geometricpp.hpp>

using namespace Geometricpp;
using namespace Quadrilaterals;

int main(void) 
{
    Rhombus losango(30, 90);

    std::cout << "Geometricpp v0.0.1.0" << std::endl;
    std::cout << std::endl;

    std::cout << "Informações sobre o Losango criado" << std::endl;
    std::cout << std::endl;

    std::cout << "Diagonais: " << losango.show_diagonals() << std::endl;
    std::cout << "Área: " << losango.area() << std::endl;
    std::cout << "Perímetro: " << losango.perimeter() << std::endl;
    std::cout << "Altura: " << losango.height() << std::endl;
    std::cout << "Raio da circunferência inscrita: " << losango.inradius() << std::endl;

    return 0;
}