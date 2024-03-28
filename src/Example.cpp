#include "Geometricpp.hpp"


int main(void) {
    Geometricpp::Square quadrado(5);

    float area = quadrado.area();
    float perimeter = quadrado.perimeter();
    double diagonal = quadrado.diagonal();

    std::cout << "Area: " << area << std::endl;
    std::cout << "Perimeter: " << perimeter << std::endl;
    std::cout << "Diagonal: " << diagonal << std::endl;
}