// geoMetricpp.hpp - Writed by @whoxer
#ifndef GEOMETRICPP_HPP
#define GEOMETRICPP_HPP

#include <iostream>
#include <cmath>


typedef double GEOMETRIC_SIDE;

namespace Geometricpp {
    class Square {
        private:
            GEOMETRIC_SIDE side_length;
        public:
            Square(GEOMETRIC_SIDE side_length) : side_length(side_length) {};

            float size(){return side_length;}

            double area() const {return pow(side_length, 2);}
            double perimeter() const {return side_length * 4;}
            double diagonal() const {return std::sqrt(2) * side_length;}
    };

    class Triangle {
        private:
            GEOMETRIC_SIDE a, b, c;
        public:
            Triangle(GEOMETRIC_SIDE a, GEOMETRIC_SIDE b, GEOMETRIC_SIDE c) : a(a), b(b), c(c) {}
            
    };
    
}


#endif