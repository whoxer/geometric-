// Square.hpp - writed by whoxer
#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <iostream>

class Square {
    private:
        float side_lenght;
    public:
        Square(double side_lenght) : side_lenght(side_lenght) { std::cout << "Square created" << std::endl;};

        double area() const {
            return side_lenght * side_lenght;
        }

        double perimeter() const {
            return side_lenght * 4;
        }
};


#endif