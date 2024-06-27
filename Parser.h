#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class point{
    double x,y;
public:
    point(double, double);
    friend double dist(point, point);
    double get_x();
    double get_y();
};

class Parser{

public:
    std::vector<point> parse(std::string);
};