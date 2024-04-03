#include "Geometricpp.hpp"

using namespace Geometricpp;
using namespace std;

int main(void) {
    Square small_square(40);

    cout << "Square size: " << small_square.size() << endl;
    cout << "Perimeter: " << small_square.perimeter() << endl;
    cout << "Area: " << small_square.area() << endl;
    cout << "Diagonal: " << small_square.diagonal() << endl;

    return 0;
}