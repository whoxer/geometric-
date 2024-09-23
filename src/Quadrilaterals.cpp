#include "../include/Quadrilaterals.hpp"


// Definição dos métodos do Quadrado.
double_t Quadrilaterals::Square::size() const {
    return side_length;
}

double_t Quadrilaterals::Square::area() const {
    return side_length * side_length;
}

double_t Quadrilaterals::Square::perimeter() const {
    return side_length * 4;
}
double_t Quadrilaterals::Square::diagonal() const {
    return std::sqrt(2) * side_length;
}

// Definição dos métodos do Retângulo
