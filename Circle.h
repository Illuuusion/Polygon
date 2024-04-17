#ifndef POLYGON_CIRCLE_H
#define POLYGON_CIRCLE_H

#include "Figure.h"

class Circle: public Figure {
private:
    Point pts;
    double radius;
public:
    double perimeter() override;
    double square() override;
    Circle(Point pts, double radius, std::string);
    std::string getType() override;
    std::string paramsToStdString() override;
};

#endif //POLYGON_CIRCLE_H
