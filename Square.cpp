#include "Square.hpp"

#include <iostream>

Square::Square(){
    side_a = 0,
    side_b = 0,
    side_c = 0,
    side_d = 0;
}

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
    if (side_a == 0)
        std::cout << "square has no value initialized yet : ";
    else
        return side_a * side_b;
    return 0;
}

Square::~Square(){}