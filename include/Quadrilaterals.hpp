#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "Geometricpp.hpp"


using namespace Geometricpp;

class Quadrilaterals::Square {
    private:
        Geometricpp::GEOMETRIC_SIDE side_length;

    public:
        explicit Square(Geometricpp::GEOMETRIC_SIDE side_length) : side_length(side_length) {};

        double_t size() const;

        double_t area() const;
        double_t perimeter() const;
        double_t diagonal() const;
};


class Quadrilaterals::Rectangle {
    private:
        Geometricpp::GEOMETRIC_SIDE x, y;
    public:
        explicit Rectangle(Geometricpp::GEOMETRIC_SIDE x, Geometricpp::GEOMETRIC_SIDE y) : x(x), y(y) {
            // Confere se lados são iguais e evita que o objeto seja criado caso tentem.
            if (x == y) {
                throw std::invalid_argument("Sides can't be equal, at least one needs to be different.");
            }
        }

};

#endif
