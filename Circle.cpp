#include "../Headers/Circle.h"

Circle::Circle(Point pts, double radius, std::string name): pts(pts), radius(radius), Figure(name){}

double Circle::perimeter(){
    return fabs(2 * M_PI * radius);
}

double Circle::square(){
    return fabs(M_PI * radius * radius);
}

std::string Circle::getType(){
    return "Circle";
}

std::string Circle::paramsToStdString(){
    std::string str = getName();
    str += "\nCenter: ";
    str += std::to_string(pts.x);
    str += ", ";
    str += std::to_string(pts.y);
    str += "\nRadius: ";
    str += std::to_string(radius);
    str += "\n";
    return str;
}


