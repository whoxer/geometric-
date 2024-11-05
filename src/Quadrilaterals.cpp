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





// Definição dos métodos do Losango.
double_t Geometricpp::Quadrilaterals::Rhombus::area() const {
    return (diagonal_a * diagonal_b) / 2;
}

double_t Geometricpp::Quadrilaterals::Rhombus::perimeter() const {
    return 4 * Geometricpp::pitagoras_diagonais(diagonal_a, diagonal_b);
}

double_t Geometricpp::Quadrilaterals::Rhombus::height const {
    
    double_t area = (diagonal_a * diagonal_b) / 2,
    side_length = pitagoras_diagonais(diagonal_a, diagonal_b);

    return area / side_length;
}

double_t Geometricpp::Quadrilaterals::Rhombus::inradius() const {

    double_t area = (diagonal_a * diagonal_b) / 2, 
    side_length = pitagoras_diagonais(diagonal_a, diagonal_b);

    double_t perimeter = 4 * side_length;

    return area / perimeter;
}

double_t Geometricpp::Quadrilaterals::Rhombus::circumradius() const {
    // code   
}