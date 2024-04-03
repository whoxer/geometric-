// geoMetricpp.hpp - Writed by @whoxer
#ifndef GEOMETRICPP_HPP
#define GEOMETRICPP_HPP

#include <iostream>
#include <cmath>

namespace Geometricpp {
    class Square {
        private:
            double side_lenght;
        public:
            Square(double side_lenght) : side_lenght(side_lenght) {};

            float size(){return side_lenght;}

            double area() const {return std::sqrt(side_lenght);}
            double perimeter() const {return side_lenght * 4;}
            double diagonal() const {return std::sqrt(2) * side_lenght;}
    };

    class Triangle {
        private:
            double a, b, c;
        public:
            Triangle(double a, double b, double c) : a(a), b(b), c(c) {
                std::cout << "Triangle of size lenght <";
                std::cout << a << ":" << b << ":" << c << std::endl;
            }
    };
    
}


#endif