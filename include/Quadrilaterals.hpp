#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "Geometricpp.hpp"

class Square {
    private:
        GEOMETRIC_SIDE side_length;

    public:
        explicit Square(GEOMETRIC_SIDE side_length) : side_length(side_length) {};

        float size() { return side_length; }

        double area() const { return side_length * side_length; }
        double perimeter() const { return side_length * 4; }
        double diagonal() const { return std::sqrt(2) * side_length; }
};


class Rectangle {
    private:
        GEOMETRIC_SIDE side_a, side_b;
    public:
        explicit Rectangle(GEOMETRIC_SIDE side_a, GEOMETRIC_SIDE side_b) : side_a(side_a), side_b(side_b) {
            // Confere se lados são iguais e evita que o objeto seja criado caso tentem.
            if (side_a == side_b) {
                throw std::invalid_argument("Sides can't be equal, at least one needs to be different.");
            }
        }
};

#endif
