#ifndef POLYGON_TRIANGLE_H
#define POLYGON_TRIANGLE_H

#include "Figure.h"

#define COUNT_POINTS 3

class Triangle: public Figure{
public:
    double perimeter() override;
    double square() override;
    std::string getType() override;
    Triangle(Point left, Point middle, Point right, std::string name);
    std::string paramsToStdString() override;
private:
    Point left, middle, right;
    double lineLength(Point pts1, Point pts2);
};

#endif //POLYGON_TRIANGLE_H
