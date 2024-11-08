#include <geometricpp/Geometricpp.hpp>

using namespace Geometricpp;

int main(void)
{
    float_t x, y, z;

    std::cout << "Geomtricpp v0.0.1.0" << std::endl;
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
