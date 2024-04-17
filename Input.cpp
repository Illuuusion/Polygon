#include "../Headers/Input.h"

std::string InputGeometry::inputName() {
    std::string name;
    std::cout << "Input name of figure: ";
    std::cin >> name;
    if (std::cin.fail()) std::cout << "Uncorrect input";
    return name;
}

Point InputGeometry::inputPointParams(){
    Point coordinate = {0, 0};
    std::cout << "Input x coordinate: ";
    std::cin >> coordinate.x;
    if (std::cin.fail()) std::cout << "Uncorrect input";
    std::cout << "Input y coordinate: ";
    std::cin >> coordinate.y;
    if (std::cin.fail()) std::cout << "Uncorrect input";
    return coordinate;
}

Circle* InputGeometry::inputCircleParams(){
    std::string name = inputName();
    Point coordinate = inputPointParams();
    double radius;
    std::cout << "Input radius of circle: ";
    std::cin >> radius;
    if (std::cin.fail()) std::cout << "Uncorrect input";
    auto* figure = new Circle(coordinate, radius, name);
    return figure;
}

Rectangle* InputGeometry::inputRectangleParams(){
    std::string name = inputName();
    Point leftCorner = inputPointParams();
    Point rightCorner = inputPointParams();
    auto* figure = new Rectangle(leftCorner, rightCorner, name);
    return figure;
}

Triangle* InputGeometry::inputTriangleParams(){
    std::string name = inputName();
    Point coordinate1 = inputPointParams();
    Point coordinate2 = inputPointParams();
    Point coordinate3 = inputPointParams();
    auto* figure = new Triangle{coordinate1, coordinate2, coordinate3, name};
    return figure;
}

unsigned InputGeometry::inputNumber(){
    unsigned number;
    std::cin >> number;
    return number;
}
