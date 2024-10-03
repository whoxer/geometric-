#include "Geometricpp.hpp"


// Definição dos métodos do Quadrado.
double_t Geometricpp::Quadrilaterals::Square::size() const {
    return side_length;
}

double_t Geometricpp::Quadrilaterals::Square::area() const {
    return side_length * side_length;
}

double_t Geometricpp::Quadrilaterals::Square::perimeter() const {
    return side_length * 4;
}
double_t Geometricpp::Quadrilaterals::Square::diagonal() const {
    return std::sqrt(2) * side_length;
}

// Definição dos métodos do Retângulo

std::pair<Geometricpp::GEOMETRIC_SIDE, Geometricpp::GEOMETRIC_SIDE> 
Geometricpp::Quadrilaterals::Rectangle::size() const {
    return std::make_pair(height, width);
}

double_t Geometricpp::Quadrilaterals::Rectangle::area() const {
    return height * width;
}

double_t Geometricpp::Quadrilaterals::Rectangle::perimeter() const {
    return 2 * (height + width);
}

double_t Geometricpp::Quadrilaterals::Rectangle::diagonal() const {
    return sqrt(pow(height, 2) + pow(width, 2));
}