#ifndef QUADRILATERALS_HPP
#define QUADRILATERALS_HPP

#include "Geometricpp.hpp"


class Geometricpp::Quadrilaterals::Square {
    private:
        Geometricpp::GEOMETRIC_SIDE side_length;

    public:
        explicit Square(Geometricpp::GEOMETRIC_SIDE side_length) : side_length(side_length) {};

        double_t size() const;

        double_t area() const;
        double_t perimeter() const;
        double_t diagonal() const;
};


class Geometricpp::Quadrilaterals::Rectangle {
    private:
        Geometricpp::GEOMETRIC_SIDE x, y;
    public:
        explicit Rectangle(Geometricpp::GEOMETRIC_SIDE x, Geometricpp::GEOMETRIC_SIDE y) : x(x), y(y) {
            // Confere se lados são iguais e evita que o objeto seja criado caso tentem.
            if (x == y) {
                throw std::invalid_argument("Sides can't be equal, at least one needs to be different.");
            }
        }

        std::pair<Geometricpp::GEOMETRIC_SIDE, Geometricpp::GEOMETRIC_SIDE> size() const;


        double_t area() const;
        double_t perimeter() const;
        double_t diagonal() const;
};

#endif