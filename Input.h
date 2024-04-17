#ifndef POLYGON_INPUT_H
#define POLYGON_INPUT_H

#include <iostream>
#include <limits>
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

#define COUNT_OF_FIGURES 3
class InputGeometry {
public:
    static std::string inputName();
    static Point inputPointParams();
    static Circle* inputCircleParams();
    static Rectangle* inputRectangleParams();
    static Triangle* inputTriangleParams();
    static unsigned inputNumber();
};

#endif //POLYGON_INPUT_H
