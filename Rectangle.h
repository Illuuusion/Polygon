#ifndef POLYGON_RECTANGLE_H
#define POLYGON_RECTANGLE_H


#include "Figure.h"

class Rectangle: public Figure{
private:
    Point leftCorner, rightCorner;
public:
    double perimeter() override;
    double square() override;
    std::string getType() override;
    Rectangle(Point leftCorner, Point rightCorner, std::string name);
    std::string paramsToStdString() override;
};


#endif //POLYGON_RECTANGLE_H
