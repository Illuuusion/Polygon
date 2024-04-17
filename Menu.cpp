#include "../Headers/Menu.h"


Menu::Menu(){
    map[1] = &Menu::addCircle;
    map.emplace(2, &Menu::addTriangle);
    map.emplace(3, &Menu::addRectangle);
    map.emplace(4, &Menu::outputFigureWithParams);
    map.emplace(5, &Menu::outputFigureWithSquareAndPerimeter);
    map.emplace(6, &Menu::outputSumOfSquaresAndSumOfPerimeters);
    map.emplace(7, &Menu::sortBySquare);
    map.emplace(8, &Menu::sortByPerimeter);
    map.emplace(9, &Menu::deleteFigure);
    map.emplace(10, &Menu::deleteFigureBySquareAndPerimeter);
}

void Menu::entry(){
    std::cout << "Enter a command:\n";
    std::cout << "1. Add circle\n2. Add triangle\n3. Add rectangle\n4. Output figures with params\n5. Output figures with squares and perimeters\n";
    std::cout << "6. Output summary of squares and perimeters\n7. Sort by squares\n8. Sort by perimeters\n9. Delete figure by number\n10. Delete figure by square and perimeter\n";
    std::cout << "11. Exit\n";
}

void Menu::run(){
    entry();
    unsigned task;
    while (isRunning) {
        std::cout << "Enter a command:\n";
        std::cin >> task;
        checkRunning(task);
        if (map.count(task))
            (this->*map[task])();
    }
}

void Menu::addCircle(){
    Figure* pFigure;
    Circle* newCircle = InputGeometry::inputCircleParams();
    pFigure = newCircle;
    figures.push_back(pFigure);
}

void Menu::addRectangle(){
    Figure* pFigure;
    Rectangle* newRectangle = InputGeometry::inputRectangleParams();
    pFigure = newRectangle;
    figures.push_back(pFigure);
}

void Menu::addTriangle(){
    Figure* pFigure;
    Triangle* newTriangle = InputGeometry::inputTriangleParams();
    pFigure = newTriangle;
    figures.push_back(pFigure);
}

void Menu::outputFigureWithParams(){
    for (auto & i : figures) std::cout << i->paramsToStdString();
}

void Menu::outputFigureWithSquareAndPerimeter(){
    for (auto & i : figures) std::cout << i->getType() << " " << i->square() << " " << i->perimeter() << "\n";
}

void Menu::outputSumOfSquaresAndSumOfPerimeters(){
    double sumSquare = 0.0;
    double sumPerimeter = 0.0;
    for (auto & i : figures){
        sumSquare += i->square();
        sumPerimeter += i->perimeter();
    }
    std::cout << "Summary of squares: " << sumSquare << "\n";
    std::cout << "Summary of perimeters: " << sumPerimeter << "\n";
}

int Menu::compareSquare(void* param1, void* param2){
    auto* prm1 = static_cast<Figure*>(param1);
    auto* prm2 = static_cast<Figure*>(param2);
    return prm2->square() - prm1->square();
}

int Menu::comparePerimeter(void* param1, void* param2){
    auto* prm1 = static_cast<Figure*>(param1);
    auto* prm2 = static_cast<Figure*>(param2);
    return prm2->perimeter() - prm1->perimeter();
}

void Menu::sortVector(int (*cmp)(void*, void*)){
    std::sort(figures.begin(), figures.end(), cmp);
}

void Menu::sortBySquare(){
    sortVector(compareSquare);
}

void Menu::sortByPerimeter(){
    sortVector(comparePerimeter);
}

void Menu::deleteFigure(){
    unsigned number = InputGeometry::inputNumber();
    --number;
    if (number > figures.size()) return;
    Figure *figure = figures.at(number);
    figures.erase(figures.begin() + number);
    delete figure;
}

void Menu::deleteFigureBySquareAndPerimeter(){
    unsigned number = InputGeometry::inputNumber();
    for (unsigned i = 0; i < figures.size(); ++i){
        if (figures.at(i)->square() > number || figures.at(i)->perimeter() > number) figures.erase(figures.begin() + i);
    }
}

void Menu::checkRunning(unsigned task) {
    isRunning = true;
    if (!map[task]) isRunning = false;
}