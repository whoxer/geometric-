#ifndef SQUARE_HPP
#define SQUARE_HPP

class Square {
    private:
        float area_p, side_a, side_b,
              side_c, side_d;
    public:
        Square();
        ~Square();

        void init(float a, float b, float c, float d);
        double Area();
};


#endif