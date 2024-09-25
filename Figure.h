#ifndef POLYGON_FIGURE_H
#define POLYGON_FIGURE_H

#include <string>
#include <algorithm>
#include <cmath>
#include "Point.h"

#define STEP 32

class Figure{
private:
    std::string name;
public:
    explicit Figure(std::string name): name(name){};
    virtual double square() = 0;
    virtual double perimeter() = 0;
    virtual std::string getType() = 0;
    virtual std::string paramsToStdString() = 0;
    std::string getName(){
        return name;
    };
};

#endif //POLYGON_FIGURE_H
