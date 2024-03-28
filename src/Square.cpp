// Square.cpp - Writed by whoxer

#include "Square.hpp"

#include <iostream>

Square::Square(){}

void Square::init(float a, float b, float c, float d) {
    side_a = a;
    side_b = b;
    side_c = c;
    side_d = d;

    if (side_a != side_b || side_b != side_c || side_c != side_d) {
        std::cout << "all the square sides must have the same value." << std::endl;
        errno;
    } else {
        std::cout << "Square of size: ";
        std::cout << side_a << ":" << side_b << ":" << side_c << ":" << side_d;
        std::cout << " created" << std::endl;
    }   
}
double Square::Area() {
    return side_a * side_a;
}

Square::~Square(){}