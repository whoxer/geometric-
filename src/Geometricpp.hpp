// geoMetricpp.hpp - Writed by whoxer
#ifndef GEOMETRICPP_HPP
#define GEOMETRICPP_HPP

#include <iostream>
#include <cmath>

namespace Geometricpp {
    class Square {
        private:
            double side_lenght;
        public:
            Square(double side_lenght) : side_lenght(side_lenght) {
                std::cout << "Square of size lenght " << side_lenght << " created" << std::endl;
            }

            double area() const {return side_lenght * side_lenght;}
            double perimeter() const {return side_lenght * 4;}
            double diagonal() const {return std::sqrt(2) * side_lenght;}
    };
}


#endif