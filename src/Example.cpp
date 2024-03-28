#include "Geometricpp.hpp"


int main(void) {
    Geometricpp::Square quadrado(5);

    float area = quadrado.area();
    float perimeter = quadrado.perimeter();

    std::cout << "Area: " << area << std::endl;
    std::cout << "Perimeter: " << perimeter << std::endl;
}