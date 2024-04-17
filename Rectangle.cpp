#include "../Headers/Rectangle.h"


Rectangle::Rectangle(Point leftCorner, Point rightCorner, std::string name): leftCorner(leftCorner)
    , rightCorner(rightCorner)
    , Figure(name){}

double Rectangle::perimeter(){
    return 2 * ((rightCorner.x - leftCorner.x) + (leftCorner.y - rightCorner.y));
}

double Rectangle::square(){
    return fabs((rightCorner.x - leftCorner.x) * (leftCorner.y - rightCorner.y));
}

std::string Rectangle::getType(){
    return "Rectangle";
}

std::string Rectangle::paramsToStdString(){
    std::string left = " \nLeft corner: ";
    left += std::to_string(leftCorner.x);
    left += ", ";
    left += std::to_string(leftCorner.y);
    std::string right = "\nRight corner: ";
    right += std::to_string(rightCorner.x);
    right += ", ";
    right += std::to_string(rightCorner.y);
    right += "\n";
    return getName() + left + right;
}

