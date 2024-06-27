#include "Parser.cpp"

class Solver{

public:
    std::vector<int> optimise(std::vector<point>);
    bool comp(point, point, point, point);
    double path_length(std::vector<point>, std::vector<int>);
};