#include "../Headers/Triangle.h"

Triangle::Triangle(Point left, Point middle, Point right, std::string name): left(left)
    , middle(middle)
    , right(right)
    , Figure(name){}

double Triangle::square(){
    return fabs(0.5 * (left.x * (middle.y - right.y) + middle.x * (right.y - left.y) + right.x * (left.y - middle. y)));
}

double Triangle::lineLength(Point pts1, Point pts2){
    return sqrt((pts1.x - pts2.x)*(pts1.x - pts2.x) + (pts1.y - pts2.y)*(pts1.y - pts2.y));
}

double Triangle::perimeter(){
    return lineLength(left, middle) + lineLength(middle, right) + lineLength(left, right);
}

std::string Triangle::getType(){
    return "Triangle";
}

std::string Triangle::paramsToStdString(){
    std::string leftCorner = "\nLeft corner: ";
    leftCorner += std::to_string(left.x);
    leftCorner += ", ";
    leftCorner += std::to_string(left.y);
    std::string middlePoint = "\nMiddle corner: ";
    middlePoint +=  std::to_string(middle.x);
    middlePoint += ", ";
    middlePoint += std::to_string(middle.y);
    std::string rightCorner = "\nLeft corner: ";
    rightCorner +=  std::to_string(right.x);
    rightCorner += ", ";
    rightCorner += std::to_string(right.y);
    rightCorner += "\n";
    return getName() + leftCorner + middlePoint + rightCorner;
}

