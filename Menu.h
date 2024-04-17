#ifndef POLYGON_MENU_H
#define POLYGON_MENU_H

#include "Input.h"
#include <vector>
#include <map>
#include "Input.h"

class Menu{
public:
    void run();
    Menu();
private:
    std::map<unsigned, void (Menu::*)()> map;
    std::vector<Figure*> figures;
    bool isRunning = true;
    void entry();
    void addCircle();
    void addTriangle();
    void addRectangle();
    void outputFigureWithParams();
    void outputFigureWithSquareAndPerimeter();
    void outputSumOfSquaresAndSumOfPerimeters();
    void sortBySquare();
    void sortByPerimeter();
    void deleteFigure();
    void deleteFigureBySquareAndPerimeter();
    static int compareSquare(void* param1, void* param2);
    static int comparePerimeter(void* param1, void* param2);
    void sortVector(int (*cmp)(void*, void*));
    void checkRunning(unsigned task);
};


#endif //POLYGON_MENU_H
